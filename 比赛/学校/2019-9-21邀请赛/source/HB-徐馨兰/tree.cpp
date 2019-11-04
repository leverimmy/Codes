#include <bits/stdc++.h>
#include <queue>
using namespace std;

const int INF=99999999;

int n,m,f[100010],nxt[100010],wei[100010],cnt,head[100010],to[100010];
bool vst[100010];
long long ans;

queue<int> q;

inline int add(int u,int v,int w){wei[++cnt]=w;to[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;}

inline int read()
{
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0' || '9'<ch) {if(ch=='-') f=-1;ch=getchar();}
	while('0'<=ch && ch<='9') res=res*10+ch-'0',ch=getchar();
	return res*f;
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read(),m=read();
	for(int i=2;i<=n;i++)f[i]=INF;
	for(int i=1;i<=m;i++){int u=read(),v=read(),w=read();add(u,v,w),add(v,u,w);}
	q.push(1);vst[1]=1;
	while(!q.empty())
	{
		int h=q.front();q.pop();
		for(int i=head[h];i;i=nxt[i])
		{
			int v=to[i];int k=max(f[h],wei[i]);f[v]=min(f[v],k);
			if(!vst[v]){vst[v]=1;q.push(v);}
		}
	}
	for(int i=1;i<=n;i++) ans+=f[i];
	cout << ans << endl;
	return 0;
}
