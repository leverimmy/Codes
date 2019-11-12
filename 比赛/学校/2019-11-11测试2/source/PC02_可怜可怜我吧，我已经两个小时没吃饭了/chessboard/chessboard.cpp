#include <bits/stdc++.h>
#define maxn 1000005
#define maxm 100005
int n,k,m,a[1005][1005],b[1005][1005],xl[maxm],xr[maxm],yl[maxm],yr[maxm],c[maxm],ver[maxm],to[maxm],vis[maxm];
char opt[maxm][10];
inline int in(int xl,int xr,int yl,int yr,int x1,int x2,int y1,int y2){
	if (x1<=xl&&xr<=x2&&y1<=yl&&yr<=y2)return 1;
	return 0;
}inline int out(int xl,int xr,int yl,int yr,int x1,int x2,int y1,int y2){
	if (x1>xr||xl>x2||y1>yr||yl>y2)return 1;
	return 0;
}
struct Quad_Tree {
	int tag[maxn<<2];
	#define ch1(x) x*4-2
	#define ch2(x) x*4-1
	#define ch3(x) x*4
	#define ch4(x) x*4+1
	void pushdown(int x){
		if (!tag[x])return;
		tag[ch1(x)]=tag[ch2(x)]=tag[ch3(x)]=tag[ch4(x)]=tag[x];tag[x]=0;
	}void modify(int x1,int x2,int y1,int y2,int xl,int xr,int yl,int yr,int v,int rt){
		if (xl>xr||yl>yr)return;
		if (in(xl,xr,yl,yr,x1,x2,y1,y2)){tag[rt]=v;return;}
		if (out(xl,xr,yl,yr,x1,x2,y1,y2))return;
		pushdown(rt);
		modify(x1,x2,y1,y2,xl,(xl+xr)>>1,yl,(yl+yr)>>1,v,ch1(rt));
		modify(x1,x2,y1,y2,((xl+xr)>>1)+1,xr,yl,(yl+yr)>>1,v,ch2(rt));
		modify(x1,x2,y1,y2,xl,(xl+xr)>>1,((yl+yr)>>1)+1,yr,v,ch3(rt));
		modify(x1,x2,y1,y2,((xl+xr)>>1)+1,xr,((yl+yr)>>1)+1,yr,v,ch4(rt));
	}void dfs(int u,int xl,int xr,int yl,int yr,int d){
		if (xl>xr||yl>yr)return;
		if (xl==xr&&yl==yr){
			if ((xl+yl)%2==d)a[xl][yl]=tag[u];
			return;
		}pushdown(u);
		dfs(ch1(u),xl,(xl+xr)>>1,yl,(yl+yr)>>1,d);
		dfs(ch2(u),((xl+xr)>>1)+1,xr,yl,(yl+yr)>>1,d);
		dfs(ch3(u),xl,(xl+xr)>>1,((yl+yr)>>1)+1,yr,d);
		dfs(ch4(u),((xl+xr)>>1)+1,xr,((yl+yr)>>1)+1,yr,d);
	}
}SGT[2];
			

int main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	scanf("%d%d%d",&n,&k,&m);
	int save=0;
	for(int i=1;i<=m;++i){
		scanf("%s",&opt[i]);
		if (opt[i][0]=='P')
			scanf("%d%d%d%d%d",&c[i],&xl[i],&yl[i],&xr[i],&yr[i]);
		if (opt[i][0]=='L'){
			int t;
			scanf("%d",&t);
			to[i]=ver[t];
		}if (opt[i][0]=='S')ver[++save]=i;
	}for(int p=m;p>=1;p--){
		vis[p]=1;
		if (opt[p][0]=='L')p=to[p];
	}for(int i=1;i<=m;++i){
		if (!vis[i]||opt[i][0]!='P')continue;
		xl[i]++;yl[i]++;xr[i]++;yr[i]++;
		int d=(xl[i]+yl[i])%2;
	//	printf("modif %d -> %d\n",i,d);
		SGT[d].modify(xl[i],xr[i],yl[i],yr[i],1,n,1,n,c[i],1);
	}
	SGT[0].dfs(1,1,n,1,n,0);SGT[1].dfs(1,1,n,1,n,1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			printf("%d ",a[i][j]==0?1:a[i][j]);
		}printf("\n");
	}
	return 0;
}
