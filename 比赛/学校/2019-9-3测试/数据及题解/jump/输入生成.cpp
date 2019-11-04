#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int n,m,cnt=0,sign=0;
int fa[100005]={0},sn[100005]={0},sm[100005]={0};
bool visit[100005]={0},h[100005]={0};
int Get(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=Get(fa[x]);
}
int main()
{		
		freopen("jump1.in","r",stdin);
		freopen("jump1.out","w",stdout);
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){ fa[i]=i; sn[i]=1; sm[i]=0; visit[i]=0; h[i]=0; }
		int x,y,X,Y;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			X=Get(x); Y=Get(y);
			if(x==y){ sm[X]++; visit[X]=1; continue; }
			if(X==Y){ sm[X]++; continue; }
			fa[X]=Y;
			sn[Y]+=sn[X];
			sm[Y]+=sm[X]+1;
			if(visit[X])visit[Y]=1; 
		}
		int ans=1;
		for(int i=0;i<m;i++)
		{
			x=Get(i);
			if(h[x])continue;
			h[x]=1;
			if(sm[x]>sn[x]){ ans=0; continue; }
			if(sm[x]==sn[x]-1){ ans=(1ll*ans*sn[x])%mod; continue; }
			if(visit[x])continue;
			ans=(ans*2ll)%mod;
		}
		printf("%d\n",ans);
	return 0;
}
