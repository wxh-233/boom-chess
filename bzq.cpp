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
			if(i==2) printf("      ÅÅÐÐ°ñ\n");
			else
			if(i==3) cout<<"      "<<wj[1].name<<" ",red,cout<<wj[1].fs<<endl;//,printf("      %s %d\n",wj[1].name.c_str(),wj[1].fs);
			else
			if(i==4) cout<<"      "<<wj[2].name<<" ",blue,cout<<wj[2].fs<<endl;//blue,printf("      %s %d\n",wj[2].name.c_str(),wj[2].fs);
			else printf("\n");
		}
		else
		{
			if(i==1) printf("      ÅÅÐÐ°ñ\n");
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
	cout<<"ÏÖÔÚÊÇ"<<wj[t].name<<"µÄ»ØºÏ!\n";
	printf("ÇëÊäÈë×ø±ê x,y\n");
//	char aaa,bbb;
//	hq:scanf("%c %c",&aaa,&bbb);
//	if(aaa<'0'||aaa>'9'||bbb<'0'||bbb>'9'){printf("ÊäÈë´íÎó\nERROR\n");goto hq;}
//	x=aaa-48;y=bbb-48;
	read(x);read(y);
//	cout<<x<<"x  y"<<y<<endl;
//	scanf("%d%d",&x,&y);
	
	if(x>dtdx||y>dtdx||x<1||y<1){printf("´ËÎ»ÖÃÒÑ³ö½ç\n");S;goto hg;}
	if(dt[x][y].player!=t&&dt[x][y].player!=0){printf("Î»ÖÃÒÑ±»ËûÈËÕ¼Áì\n");S;goto hg;}
	dt[x][y].sz+=1;
	dt[x][y].player=t;
	if(dt[x][y].sz<pdbz(x,y)) return;
	q.push(dl{1,x,y});
	cls;
	BFS();
	cout<<wj[t].name<<"µÄ»ØºÏ½áÊø\n";
	S;
	return;
//	printf("ÏÖÔÚÊÇ%sµÄ»ØºÏ!\n",wj[t].name);
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
±¬Õ¨Æå¿ÆÆÕ£º
»ñÊ¤·½·¨£º³¡ÉÏÆäËûÈË¶¼Ã»ÓÐÆå×ÓÊ±»ñÊ¤¡£
ÓÎÏ·¹æÔò£ºÔÚÆåÅÌÉÏ²¼ÖÃÒ»¸öÆå×Ó£¬Ã¿¸öÆå×Ó¶¼ÓÐ²»Ò»ÑùµÄÒý±¬ÊýÁ¿£¬
Ë×³Æ¡°½ð½ÇÒø±ßÍ­¶ÇÆ¤¡±£¬ÆäÒâË¼ÊÇ½ÇÂäµÄ¼ÛÖµ×î¸ß£¬Ö»ÐèÒªÁ½¸öÆå×Ó¾Í
ÄÜÒý±¬¡£Òý±¬ºóÆå×Ó»á³¯ËÄÖÜËÄÉ¢·½¿é£¬ÆäËûÑÕÉ«µÄÆå×Ó±»ÎÒ·½Æå×Ó±¬¿ª
µÄËéÆ¬´òÖÐºó»á±ä³ÉÃ»ÓÐÑÕÉ«µÄ¿ÕÎ»£¬Èç¹ûËéÆ¬¸ÕºÃÂäµ½ÁËÆäËûÑÕÉ«µÄÖ»
Ê£Ò»¸ö¾Í»áÒý±¬µÄÆå×ÓÉÏ£¬Ôò»á¼ÌÐø´¥·¢Òý±¬£¬²»¹ýÑÕÉ«±ä³ÉÁËÄãµÄÑÕÉ«
¡£¿ØÖÆµÃµ½¿ÉÒÔÒýÆðÁ¬»·±¬Õ¨£¬·´°ÜÎªÊ¤¡£
ÍØÕ¹Íæ·¨£º¡¾ÃÔÎí¾Ö¡¿ÄãÖ»ÖªµÀ×Ô¼ºÏÂÔÚÁËÄÄÀï£¬ÆäËûÈËµÄÑÕÉ«¾ùÎª»ÒÉ«
£¨Ò²²»»áÏÔÊ¾Ã¿¸ñÄÚµÄÆå×ÓÊý£©
¡¾ÃÔ¹¬¾Ö¡¿²»¹æÔòÆåÅÌ£¬ÓÐ¸ü¶àµÄ±ß½Ç
ÁíÍâ±¬Õ¨ºó»á±ä³ÉÃ»ÓÐÑÕÉ«µÄ¿Õ¸ñ

Ê¤ÀûÌõ¼þ£º³¡ÉÏÆäËûÈË¶¼Ã»ÓÐÆå×ÓÊ±»ñÊ¤¡£
¹æÔò£ºÔÚÆåÅÌÉÏ²¼ÖÃÒ»¸öÆå×Ó£¬Ã¿¸öÆå×Ó¶¼ÓÐ²»Ò»ÑùµÄÒý±¬ÊýÁ¿£¬½ÇÂäµÄ
¼ÛÖµ×î¸ß£¬Ö»ÐèÒªÁ½¸öÆå×Ó¾ÍÄÜÒý±¬£¬±ß3¸ö£¬ÖÐÐÄ4¸ö¡£Òý±¬ºó»á³¯ËÄÉ¢
·½¿é£¬Òý±¬µÄÎ»ÖÃ»á±ä³É¿ÕÎ»£¬ÆäËûÑÕÉ«µÄÆå×Ó±»ÎÒ·½Æå×Ó±¬¿ªµÄËéÆ¬´ò
ÖÐºó»á±ä³É¼º·½ÑÕÉ«£¬Èç¹ûËéÆ¬¸ÕºÃÂäµ½ÁËÖ»Ê£Ò»¸ö¾Í»áÒý±¬µÄÆå×ÓÉÏ£¬
Ôò»á¼ÌÐøÒý±¬¡£
*/
	cls;
	
	printft("»¶Ó­À´µ½½ÌÑ§»·½Ú",50,1);
	S;
	cls;
	printft("ÏÖÔÚ½²½â¹æÔò",50,0);
	S;
	cls;
	printft("ÕâÊÇÒ»¸ö3x3µÄÆåÅÌ\n",50,0);
	ss;
	printf("0 0 0\n0 0 0\n0 0 0\n");
	S;
	cls;
	printf("0 0 0\n0 0 0\n0 0 0\n");
	ss;
	printf("ÆåÅÌµÄÃ¿Ò»¸ö¸ñ×Ó·ÖÎª3ÖÖÇé¿ö\n");
	S;
	printft("ÖÐÐÄ     ±ß     ½Ç\n",50,0);
	pause;
	cls;
	printf("¶Ô¾Ö¿ªÊ¼ºóÃ¿ÃûÍæ¼ÒÂÖÁ÷ÏòÆåÅÌÖÐÏÂÒ»¿Å×Ó\n");
	S;
	printf("²»ÔÊÐíÏÂÔÚÆåÅÌÍâºÍÆäËûÈËµÄÆå×ÓÕ¼ÁìÖ®µØ\n");
	S;
	pause;
	cls; 
	printf("µ±Ò»¸öÈËµÄÆå×ÓÏÂÔÚ¿ÕµØ£¬Èç(1,1)£¬¾Í»áÕ¼ÁìÕâ¿éµØ·½\n");
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
	printf("#                  1.PLAY Ë«ÈËpvp            #\n");
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
		cout<<"ÇëÊäÈëplayer"<<i<<"µÄÃû×Ö"<<endl;
		cin>>wj[i].name;
		if(pc(wj[i].name,i)){printf("Ãû×ÖÖØ¸´\n");S;goto mz;}
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
	printf("%s»ñµÃÁËÊ¤Àû!",wj[win].name.c_str()); 
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
