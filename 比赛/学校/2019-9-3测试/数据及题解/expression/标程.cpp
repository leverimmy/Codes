#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,cnt=0;
int a[505]={0};
char s[505];
double p[505];
double Get(int x)
{
	double b[300];
	if(a[0]&(1<<x))b[0]=1;
	else b[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]&(1<<x))
		{
			if(s[i]=='|')b[i]=p[i]*b[i-1]+(1-p[i]);
			if(s[i]=='&')b[i]=p[i]*b[i-1]+(1-p[i])*b[i-1];
			if(s[i]=='^')b[i]=p[i]*b[i-1]+(1-p[i])*(1-b[i-1]);
		}
		else
		{
			if(s[i]=='|')b[i]=p[i]*b[i-1]+(1-p[i])*b[i-1];
			if(s[i]=='&')b[i]=p[i]*b[i-1];
			if(s[i]=='^')b[i]=p[i]*b[i-1]+(1-p[i])*b[i-1];
		}
	}
	return b[n];
}
int main()
{	
	freopen("expression10.in","r",stdin);
	freopen("expression10.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>p[i];
	double ans=0;
	for(int i=0;i<=20;i++)ans+=(1<<i)*1.0*Get(i);
	cnt++;
	printf("%.4lf\n",ans);
	return 0;
}
