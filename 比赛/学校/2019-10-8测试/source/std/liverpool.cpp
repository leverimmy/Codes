#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000010
using namespace std;
char s[N];
int ch[N][27],w[N],cnt=1;
void addnew(int W)
{
	int n=strlen(s),now=1,x,i;
	for(i=0;i<n;i++)
	{
		x=s[i]-96;
		if(!ch[now][x])
		{
			cnt++;
			w[cnt]=-1;
			ch[now][x]=cnt;
		}
		now=ch[now][x];
	}
	w[now]=W;
}
int find()
{
	int n=strlen(s),now=1,x,i;
	for(i=0;i<n;i++)
	{
		x=s[i]-96;
		now=ch[now][x];
	}
	return w[now];
}
int main()
{
	freopen("liverpool.in","r",stdin);
		freopen("liverpool.out","w",stdout);
	int n,m;
	scanf("%d",&n);
	int i,j,x,y;
	w[0]=-1;
	for(i=1;i<=n;i++)
	{
		scanf("%s%d",s,&x);
		addnew(x);
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&x);
		long long ans=0;
		bool cant=false;
		while(x--)
		{
			scanf("%s",s);
			y=find();
			if(y==-1) cant=true;
			else ans+=y;
		}
		if(cant) puts("-1");
		else printf("%lld\n",ans);
	}
}
