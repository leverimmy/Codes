#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#define N 200010
#define M 400010
#define inf 707185547
using namespace std;
void NO(){puts("NIE");exit(0);}
int n,m;
int A[M],B[M],C[M];
int du[N];
int to[M],nxt[M],pre[N],w[M],cnt=1;
void ae(int ff,int tt,int ww)
{
	cnt++;
	to[cnt]=tt;
	nxt[cnt]=pre[ff];
	w[cnt]=ww;
	pre[ff]=cnt;
	cnt++;
	to[cnt]=ff;
	nxt[cnt]=pre[tt];
	w[cnt]=0;
	pre[tt]=cnt;
}
int S,E;
int q[N],h,t,d[N];
bool bfs()
{
	memset(d,0,sizeof(d));
	d[S]=1;q[1]=S;
	h=t=1;
	int i,j,x,y;
	while(h<=t)
	{
		x=q[h];h++;
		for(i=pre[x];i;i=nxt[i])
		if(w[i])
		{
			j=to[i];
			if(!d[j])
			{
				d[j]=d[x]+1;
				t++;q[t]=j;
			}
		}
	}
	if(d[E]) return true;
	return false;
}
int dfs(int x,int v)
{
	if(x==E||v==0) return v;
	int i,j,ret=0;
	for(i=pre[x];i;i=nxt[i])
	if(w[i])
	{
		j=to[i];
		if(d[j]!=d[x]+1) continue;
		int f=dfs(j,min(v,w[i]));
		w[i]-=f;
		w[i^1]+=f;
		v-=f;
		ret+=f;
		if(v==0) break;
	}
	if(ret==0) d[x]=-1;
	return ret;
}
int dinic()
{
	int ret=0;
	while(bfs())
	ret+=dfs(S,inf);
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,j,x,y,c,d,tot=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&A[i],&B[i],&C[i]);
		du[A[i]]++;du[B[i]]--;
		ae(C[i],B[i],1);
	}
	for(i=1;i<=n;i++)
	tot+=abs(du[i]);
	tot/=2;
	S=0;E=n+1;
	for(i=1;i<=n;i++)
	{
		if(du[i]>0) ae(S,i,du[i]);
		else if(du[i]<0) ae(i,E,-du[i]);
	}
	if(dinic()!=tot) NO();
	for(i=1;i<=m;i++)
	printf("%d",w[i<<1]^1);
}