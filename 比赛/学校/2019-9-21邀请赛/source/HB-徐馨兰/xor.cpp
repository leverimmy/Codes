#include <bits/stdc++.h>
using namespace std;

const int INF=99999999;

int t,n,m;
int a[100010];

struct note{int x,y,w;}que[100010];

bool cmp(note a,note b){if(a.x==b.x)return a.y<b.y; return a.x<b.x;}

inline int read()
{
	int res=0,f=1;char ch=getchar();
	while(ch<'0' || '9'<ch){if(ch=='-') f=-1;ch=getchar();}
	while('0'<=ch && ch<='9') res=res*10+ch-'0',ch=getchar();
	return res*f;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	t=read();
	for(int test=1;test<=t;test++)
	{
		memset(que,0,sizeof(que));memset(a,0,sizeof(a));n=read(),m=read();int cnt=0;int fin=0;
		for(int i=1;i<=n;i++)a[i]=INF;
		for(int i=1;i<=m;i++)
		{
			int x=read(),y=read(),kw=read(),l=0;int w=kw;
			if(x==y) if(a[x]==INF){a[x]=w;continue;} else if(a[x]!=w){printf("No\n");fin=1;break;}
			x=min(x,y);y=max(x,y);
			if(w==0) if(a[x]!=INF && a[y]!=INF){if(a[x]!=a[y]) {printf("No\n");fin=1;break;}} else if(a[x]!=INF)a[y]=a[x]; else if(a[y]!=INF)a[x]=a[y];
			for(int j=x;j<=y;j++) if(a[j]==INF){fin=-1;break;} else l=l^a[j],x++,w=w^a[j];
			for(int j=y;j>=x;j++) if(a[j]==INF) break; else y--,w=w^a[j];
			if(x==y){a[x]=w;continue;}
			if(fin==0 && l!=kw) {printf("No\n");fin=1;break;}
			que[++cnt].x=x,que[cnt].y=y,que[cnt].w=w;
		}
		if(fin==1) continue;
		sort(que+1,que+cnt+1,cmp);
		for(int i=1;i<=m;i++)
		{
			int x=que[i].x,y=que[i].y,w=que[i].w,l=0,xl=que[i-1].x,yl=que[i-1].y,wl=que[i-1].w;
			if(x==xl&&y==yl+1) if(a[y]==INF)a[y]=w^wl; else if(a[y]!=w^wl) {printf("No\n");fin=1;break;}
			if(y==yl&&x==xl+1) if(a[xl]==INF)a[xl]=w^wl; else if(a[xl]!=w^wl) {printf("No\n");fin=1;break;}
			for(int j=x;j<=y;j++) if(a[j]==INF){fin=-1;break;} else l=l^a[j],x++,que[i].w=que[i].w^a[j];
			for(int j=y;j>=x;j++) if(a[j]==INF) break; else y--,w=w^a[j];
			if(x==y){a[x]=w;continue;}
			if(fin==0 && l!=w) {printf("No\n");fin=1;break;}
		}
		if(fin==1) continue;
		sort(que+1,que+cnt+1,cmp);
		for(int i=1;i<=m;i++)
		{
			int x=que[i].x,y=que[i].y,w=que[i].w,l=0,xl=que[i-1].x,yl=que[i-1].y,wl=que[i-1].w;
			if(x==xl&&y==yl+1) if(a[y]==INF)a[y]=w^wl; else if(a[y]!=w^wl) {printf("No\n");fin=1;break;}
			if(y==yl&&x==xl+1) if(a[xl]==INF)a[xl]=w^wl; else if(a[xl]!=w^wl) {printf("No\n");fin=1;break;}
			for(int j=x;j<=y;j++) if(a[j]==INF){fin=-1;break;} else l=l^a[j],x++;
			for(int j=y;j>=x;j++) if(a[j]==INF) break; else y--,que[i].w=que[i].w^a[j];
			if(x==y){a[x]=w;continue;}
			if(fin==0 && l!=w) {printf("No\n");fin=1;break;}
		}
		if(fin==1) continue;
		printf("Yes\n");
	}
	return 0;
}
/*
2
3 2
1 2 1
2 3 0
2 3
1 1 1
2 2 1
1 2 1
*/
