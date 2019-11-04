#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define inf 0x7fffffff
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[5],v[5],num[15],sum;
int tot;
bool jud1()
{
	memset(num,0,sizeof(num));
	for(int i=0;i<=4;i++)
	{
	    num[a[i]]++;
	    if(num[a[i]]==4)return 1;
	}
	return 0;
}
bool jud2()
{
	for(int i=0;i<=4;i++)
	    if(a[i]<=10)return 0;
	return 1;
}
bool jud3()
{
	if(sum>10)return 0;
	for(int i=0;i<=4;i++)
	    if(a[i]>=5)return 0;
	return 1;
}
bool judhead()
{
	for(int i=0;i<=4;i++)
	     for(int j=i+1;j<=4;j++)
	         if((sum-v[i]-v[j])%10==0)return 1;
    return 0;	
}
int getans()
{
	sum=0;
	for(int i=0;i<=4;i++)
	    sum+=v[i];
	if(jud3())return 60;
	if(jud2())return 50;
	if(jud1())return 40;
	if(!judhead())return 0;
	int t=sum%10;
	if(t<=6&&t!=0)return t;
	else if(t!=0)return t*2;
	else return 30;
}
int main()
{
	freopen("niuniu5.in","r",stdin);
	freopen("niuniu5.out","w",stdout);
	int T=read();
	while(T--)
	{
		tot=0;
        for(int i=0;i<4;i++)a[i]=read();
        for(int i=0;i<4;i++)v[i]=min(a[i],10);
        for(int i=1;i<=13;i++)
        {
        	a[4]=i;v[4]=min(a[4],10);
        	int t=getans();
        	tot+=t;
        }
        printf("%.0lf\n",(double)tot/13);
    }
	return 0;
}
