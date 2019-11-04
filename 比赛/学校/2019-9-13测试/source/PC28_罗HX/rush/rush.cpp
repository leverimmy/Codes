#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;
const int mn=100010;
int n,m;
int r,c;
bool lef[mn];
bool righ[mn];
bool up[mn];
bool down[mn];
int getint()
{
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	int x=0;
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int cnt;
int main()
{
	freopen("rush.in","r",stdin);
	freopen("rush.out","w",stdout);
	n=getint();
	m=getint();
	cnt=n*4;
	for(int i=1;i<=m;i++)
	{
		r=getint();
		c=getint();
		if(righ[r]==0)righ[r]=lef[r]=1,cnt-=2;
		if(up[c]==0)up[c]=down[c]=1,cnt-=2;
	}
	if(n%2==0)cout<<cnt/2<<endl;
	else
	{
		if(up[n/2+1]==0 && lef[n/2+1]==0)cout<<cnt/2-1<<endl;
		else cout<<cnt/2<<endl;
	}
	return 0;
}
