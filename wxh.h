#ifndef wxh_h_
#define wxh_h_
#include<bits/stdc++.h>
#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#define cls system("cls")
#define pause system("pause")
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define PIE 3.14
#define pows(a) a*a
#define S Sleep(1000)
#define ss Sleep(250)
#define sss Sleep(100)
#define pmzb(a,b,c,d) abs(c-a)+abs(d-b)//平面坐标 
#define white SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE)
#define red SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED)
#define green SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN)
#define blue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE)
#define yellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |	FOREGROUND_GREEN)
#define pink SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE)
#define qs SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE)
#define cyan SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE)
#define gray SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY)
using namespace std;
inline void read(int &x)
{
	x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar());
	x=ch-48;
//	for(;isdigit(ch);ch=getchar()) x=((x<<3)+(x<<1))+ch^15;
}
void printft(string s,int t,bool z)
{
	if(z==1)
		system("chcp 936"),
		cls; 
	for(int i=0;i<s.size();i++)
		cout<<s[i],Sleep(t);
}
char getin(string zzz)
{
	if(zzz=="bool")
	{
		char c=getchar();
		while(c!=48&&c!=49) c=getchar();
		int a=c&15;
		return a?true:false;
	}
	if(zzz=="char")
	{
		char c=getchar();
		while(c==127||c<=32)
			c=getchar();
		return c;
	}
	if(zzz=="int")
	{
		int flag=0;
		int c=getchar();
		while(c>57||c<48&&c!='-')
			c=getchar();
		if(c=='-') flag=true,c=getchar();
		int x=0;
		while (c<=57&&c>=48) x=(x<<3)+(x<<1)+(c&15),c=getchar();
		return flag?-x:x;
	}
}
/*
bool getin_bool()
{
	char c=getchar();
	while(c!=48&&c!=49) c=getchar();
	int a=c&15;
	return a?true:false;
}
char getin_char()
{
	char c=getchar();
	while(c==127||c<=32)
		c=getchar();
	return c;
}
int getin_int()
{
	int flag=0;
	int c=getchar();
	while(c>57||c<48&&c!='-')
		c=getchar();
	if(c=='-') flag=true,c=getchar();
	int x=0;
	while (c<=57&&c>=48) x=(x<<3)+(x<<1)+(c&15),c=getchar();
	return flag?-x:x;
	//if(flag) return -x;
	//else	 return  x;
}
*/
void ht()
{
	HWND hwnd;
	hwnd=FindWindow("ConsoleWindowClass",NULL);
	if(hwnd)
	{
		ShowWindow(hwnd,SW_HIDE);
	}
}
void gj()
{
	system("shutdown -s -t 10 -c '你使用了wxh头文件关机，\n离关机剩余10s'"); 
}
void tzgj()
{
	system("shutdown -a");
}
void cmd()
{
	system("start");
}
int sjs(int a,int b)
{
	int c;
	srand((unsigned)time(NULL));
	c=rand();
	c=c%b+a;
	return c;
}
int zh(char a)
{
	int b;
	b=a-48;
	return b;
} 
char zh(int a)
{
	a+=48;
	char b;
	b=a;
	return b;
}
#endif
