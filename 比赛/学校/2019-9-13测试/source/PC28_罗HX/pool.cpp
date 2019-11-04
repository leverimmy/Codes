#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;
const int mod=1000000007;
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
int t,k;
int l,r;
int cnt;
int d;
void work(int i,bool b)
{
	if(d>r)return;
	if(l<=d && d<=r)
	{
	    cnt++;
	    cnt=cnt%mod;
	}
	d++;
	work(i+1,1);
	d--;
	if(b)
	{
		d+=k;
		work(i+k,0);
		d-=k;
	}
}
int main()
{
	freopen("pool.in","r",stdin);
	freopen("pool.out","w",stdout);
	t=getint();
	k=getint();
	for(int i=1;i<=t;i++)
	{
		l=getint();
		r=getint();
		cnt=0;
		work(0,1);
		cout<<cnt<<endl;
	}
	return 0;
}
