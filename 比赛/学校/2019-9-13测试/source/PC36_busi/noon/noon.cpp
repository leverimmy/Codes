#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,m,ans;
int h[maxn];
float ratio[maxn];

int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch)
	{
		if (ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
 
int main()
{
	freopen("noon.in","r",stdin);
	freopen("noon.out","w",stdout);
	memset(ratio,0.00,sizeof(ratio));
	memset(h,0,sizeof(h));
	n=read(),m=read();
	while(m--)
	{
		int x,y,ccx,ccx_nb;
		float max_ratio=0.00;
		int max_high=0;
		x=read(),y=read();
		ans=0;
		h[x]=y,ratio[x]=y/x;
		for(int i=n;i>=1;i--)
		{
			if(h[i]>max_high)
			{
				max_high=h[i];
				ccx=i;
			}
			if(ratio[i]>=max_ratio)
			{
				max_ratio=ratio[i];
				ccx_nb=i;
			}
			else continue;
		}
		for(int i=1;i<ccx_nb;i++)
		{
			if(h[i]==0) continue;
			else ans++;
		}
		printf("%d\n",ans+1); 
	}
	return 0;
}
