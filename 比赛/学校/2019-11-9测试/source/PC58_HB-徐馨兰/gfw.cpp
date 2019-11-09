#include <bits/stdc++.h>
using namespace std;

int read()
{
	int res=0,p=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')p=-1; ch=getchar();}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*p;
}

int n,m,cnt;
int ans,a[200010];

struct note
{
	int s,e,num;
}que[200010];

int main()
{
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	que[++cnt].s=1,que[cnt].num=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]<=a[i-1])
		{
			que[cnt].e=i-1;
			que[++cnt].s=i;
		}
		que[cnt].num++;
	}
	que[cnt].e=n;
	for(int i=1;i<=cnt;i++)
	{
		int num=que[i].num;
		for(int j=i+1;j<=cnt;j++)
		{
			int k=que[i].num;
			k+=que[j].num;
			for(int p=que[j].s;p<=que[j].e;p++)
			{
				if(a[p]>a[que[i].e]) break;
				k--;
			}
			num=max(num,k);
		}
		ans=max(ans,num);
	}
	for(int i=1;i<=cnt;i++)
	{
		int num=que[i].num;
		for(int j=i+1;j<=cnt;j++)
		{
			int k=que[i].num;
			k+=que[j].num;
			for(int p=que[i].e;p>=que[i].s;p--)
			{
				if(a[p]<a[que[j].s]) break;
				k--;
			}
			num=max(num,k);
		}
		ans=max(ans,num);
	}
	cout << ans << endl;
	return 0;
}
