#include<bits/stdc++.h>
#include<windows.h>
#include<string.h>
#include"wxh.h"
using namespace std;
int n=2,dtdx=3;
void say(string s)
{
	for(int i=0;i<s.size();i++)
	{
		putchar(s[i]);
		sss;
	}
}
struct maps{
	int player,sz;
}dt[15][15];
struct player{
	int xh;
	string name;
	int fs;
//	void csh(int n,player wj[])
//	{
//		for(int i=1;i<=n;i++)
//			wj[i].xh=i;
//	}
}wj[100];
int jc(int n)
{
	for(int i=1;i<=n;i++)
		if(wj[i].fs<=0)
			return 0;
	return 1;
}
void print()
{
	for(int i=1;i<=dtdx;i++)
	{ 
		for(int j=1;j<=dtdx;j++)
		{
			if(!dt[i][j].sz) dt[i][j].player=0;
			switch (dt[i][j].player){
				case 0 : white;break;
				case 1 : red;break;
				case 2 : blue;break; 
			};
			printf("%d ",dt[i][j].sz);
		}
		white;
		if(dtdx>3)
		{
			if(i==2) printf("      排行榜\n");
			else
			if(i==3) cout<<"      "<<wj[1].name<<" ",red,cout<<wj[1].fs<<endl;//,printf("      %s %d\n",wj[1].name.c_str(),wj[1].fs);
			else
			if(i==4) cout<<"      "<<wj[2].name<<" ",blue,cout<<wj[2].fs<<endl;//blue,printf("      %s %d\n",wj[2].name.c_str(),wj[2].fs);
			else printf("\n");
		}
		else
		{
			if(i==1) printf("      排行榜\n");
			else
			if(i==2) cout<<"      "<<wj[1].name<<" ",red,cout<<wj[1].fs<<endl;//,printf("      %s %d\n",wj[1].name.c_str(),wj[1].fs);
			else
			if(i==3) cout<<"      "<<wj[2].name<<" ",blue,cout<<wj[2].fs<<endl;//blue,printf("      %s %d\n",wj[2].name.c_str(),wj[2].fs);
			else printf("\n");
		}
		white;
	}
	white;
}
struct dl{
	int c;
	int x,y;
};
queue<dl>q;
int pdbz(int x,int y)
{
	if((x==1&&y==1)||(x==dtdx&&y==dtdx)||(x==1&&y==dtdx)||(x==dtdx&&y==1)) return 2;
	if(x==1||y==1||x==dtdx||y==dtdx) return 3;
	return 4;
}
void fs()
{
	int js[10]={0};
	for(int i=1;i<=dtdx;i++)
		for(int j=1;j<=dtdx;j++)
			if(dt[i][j].player!=0)
				js[dt[i][j].player]++;
	for(int i=1;i<=2;i++)
		wj[i].fs=js[i];
//	cout<<endl<<wj[1].fs<<" "<<wj[2].fs<<endl;
}
void BFS()
{
	int dx[10]={0,1,-1,0,0},dy[10]={0,0,0,1,-1};
	while(!q.empty())
	{
		dl tmp=q.front();q.pop();
		int x=tmp.x,y=tmp.y;
		if(dt[x][y].sz<pdbz(x,y)) continue;
		for(int i=1;i<=4;i++)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>dtdx||yy>dtdx||xx<1||yy<1) continue;
			if(dt[x][y].sz<pdbz(x,y)) continue;
			dt[xx][yy].player=dt[x][y].player;
			dt[xx][yy].sz++;
			if(dt[xx][yy].sz>=pdbz(xx,yy)/*dt[xx][yy].sz>=bz[xx][yy]*/) q.push(dl{tmp.c+1,xx,yy});
		}
		if(dt[x][y].sz>=pdbz(x,y))
			dt[x][y].sz-=pdbz(x,y);
		if(dt[x][y].sz==0)
			dt[x][y].player=0;
		fs();
		dl bh=q.front();
		if(bh.c!=tmp.c)
			cls,print(),ss;
	}
}
void hh(int t)
{
	hg:cls;
	int x,y;
	fs();
	print();
	cout<<endl;
	cout<<"现在是"<<wj[t].name<<"的回合!\n";
	printf("请输入坐标 x,y\n");
//	char aaa,bbb;
//	hq:scanf("%c %c",&aaa,&bbb);
//	if(aaa<'0'||aaa>'9'||bbb<'0'||bbb>'9'){printf("输入错误\nERROR\n");goto hq;}
//	x=aaa-48;y=bbb-48;
	read(x);read(y);
//	cout<<x<<"x  y"<<y<<endl;
//	scanf("%d%d",&x,&y);
	
	if(x>dtdx||y>dtdx||x<1||y<1){printf("此位置已出界\n");S;goto hg;}
	if(dt[x][y].player!=t&&dt[x][y].player!=0){printf("位置已被他人占领\n");S;goto hg;}
	dt[x][y].sz+=1;
	dt[x][y].player=t;
	if(dt[x][y].sz<pdbz(x,y)) return;
	q.push(dl{1,x,y});
	cls;
	BFS();
	cout<<wj[t].name<<"的回合结束\n";
	S;
	return;
//	printf("现在是%s的回合!\n",wj[t].name);
//	pause;
	
}
int pc(string s,int t)
{
	for(int i=1;i<t;i++)
		if(s==wj[i].name) return 1;
	return 0;
}
void study()
{
/*
爆炸棋科普：
获胜方法：场上其他人都没有棋子时获胜。
游戏规则：在棋盘上布置一个棋子，每个棋子都有不一样的引爆数量，
俗称“金角银边铜肚皮”，其意思是角落的价值最高，只需要两个棋子就
能引爆。引爆后棋子会朝四周四散方块，其他颜色的棋子被我方棋子爆开
的碎片打中后会变成没有颜色的空位，如果碎片刚好落到了其他颜色的只
剩一个就会引爆的棋子上，则会继续触发引爆，不过颜色变成了你的颜色
。控制得到可以引起连环爆炸，反败为胜。
拓展玩法：【迷雾局】你只知道自己下在了哪里，其他人的颜色均为灰色
（也不会显示每格内的棋子数）
【迷宫局】不规则棋盘，有更多的边角
另外爆炸后会变成没有颜色的空格

胜利条件：场上其他人都没有棋子时获胜。
规则：在棋盘上布置一个棋子，每个棋子都有不一样的引爆数量，角落的
价值最高，只需要两个棋子就能引爆，边3个，中心4个。引爆后会朝四散
方块，引爆的位置会变成空位，其他颜色的棋子被我方棋子爆开的碎片打
中后会变成己方颜色，如果碎片刚好落到了只剩一个就会引爆的棋子上，
则会继续引爆。
*/
	cls;
	
	printft("欢迎来到教学环节",50,1);
	S;
	cls;
	printft("现在讲解规则",50,0);
	S;
	cls;
	printft("这是一个3x3的棋盘\n",50,0);
	ss;
	printf("0 0 0\n0 0 0\n0 0 0\n");
	S;
	cls;
	printf("0 0 0\n0 0 0\n0 0 0\n");
	ss;
	printf("棋盘的每一个格子分为3种情况\n");
	S;
	printft("中心     边     角\n",50,0);
	pause;
	cls;
	printf("对局开始后每名玩家轮流向棋盘中下一颗子\n");
	S;
	printf("不允许下在棋盘外和其他人的棋子占领之地\n");
	S;
	pause;
	cls; 
	printf("当一个人的棋子下在空地，如(1,1)，就会占领这块地方\n");
	ss;
	blue;printf("1 ");white;printf("0 0\n0 0 0\n0 0 0\n");
	S;
	
	pause; 
	
	
}
int main()
{
//	system("chcp 936");
	white;
	printf("##############################################\n");
	printf("#                                            #\n");
	printf("#                                            #\n");
	printf("#                  1.PLAY 双人pvp            #\n");
	printf("#                                            #\n");
	printf("#                                            #\n");
	printf("#                  2.STUDY                   #\n");
	printf("#                                            #\n");
	printf("#                                            #\n");
	printf("##############################################\n");
	int x;
	cin>>x;
	if(x==2) study();
	for(int i=1;i<=n;i++)
		wj[i].xh=i;
	for(int i=1;i<=n;i++)
	{
		mz:
		cls;
		cout<<"请输入player"<<i<<"的名字"<<endl;
		cin>>wj[i].name;
		if(pc(wj[i].name,i)){printf("名字重复\n");S;goto mz;}
		ss;
	}
	cls;
	S;
	int flag=0;
	int r;
	say("game start!");
	do{
//		hh(r);
//		fs
//		r+1;
//		if(r>n) r-=n;
		for(int r=1;r<=n;r++)
		{
			hh(r);
			fs();
			if(flag&&!jc(n))
				goto bye;
		}
		flag=1;
	}while(jc(n));
	bye://cout<<flag;return 0;
	cls;
	print();
	int win;
	for(int i=1;i<=n;i++)
		if(wj[i].fs){win=i;break;}
	printf("%s获得了胜利!",wj[win].name.c_str()); 
//	hh(1);
	pause;
	return 0;
}
/*



inline void read(int &x)
{
	x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar());
	x=ch-48;
//	for(;isdigit(ch);ch=getchar()) x=((x<<3)+(x<<1))+ch^15;
}
#define white SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE)
#define red SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED)
#define green SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN)
#define blue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE)
#define yellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |	FOREGROUND_GREEN)
#define pink SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE)
#define qs SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE)
#define cyan SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE)
#define gray SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY)
#define cls system("cls")
#define pause system("pause")
#define S Sleep(1000)
#define ss Sleep(250)
#define sss Sleep(100)
*/

