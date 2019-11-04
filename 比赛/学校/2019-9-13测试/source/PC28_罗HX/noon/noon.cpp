#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;
const int mn=100010;
double getd()
{
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	double x=0;
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
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
int n,m;
int x;
double xx;
double y;
double h[mn];
double a[mn];
double maxx;
int cnt;
int main()
{
	freopen("noon.in","r",stdin);
	freopen("noon.out","w",stdout);
	cin>>n>>m;
	if(n*m<=1001*1001)
	{
	    for(int i=1;i<=m;i++)
	    {
		    x=getint();
	    	y=getd();
		    xx=x;
		    h[x]=y;
		    a[x]=y/xx;
		    maxx=0;
		    cnt=0;
		    for(int j=1;j<=n;j++)
		    {
			    if(a[j]>0 && a[j]>maxx)
			    {
				    cnt++;
				    maxx=a[j];
			    }
		    }
		    cout<<cnt<<endl;
	    }
    }
    else
    {
    	for(int i=1;i<=m;i++)
    	{
    		x=getint();
    		y=getd();
    		xx=x;
    		a[x]=y/xx;
    		if(a[x]>maxx)cnt++;
    		maxx=max(maxx,a[x]);
    		cout<<cnt<<endl;
		}
	}
	return 0;
}
