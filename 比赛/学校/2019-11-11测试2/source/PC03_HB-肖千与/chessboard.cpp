#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
const int N=1005,M=100005;
int n,k,m,cnt;
struct Q{
	int c,x1,x2,y1,y2;
}q[M],tq[M];
int pre[M],ver[M];
int b[N][N];
struct Segment_tree{
	int col[N<<2];
	#define ls rt<<1
	#define rs rt<<1|1
	inline void push_down(int rt){
		if(col[rt]!=-1) {
			col[ls]=col[rt];
			col[rs]=col[rt];
			col[rt]=-1;
		}
	}
	inline void update(int rt,int l,int r,int L,int R,int c){
		if(L>R) return;
		if(L<=l&&r<=R) {
			col[rt]=c;
			return;
		}
		push_down(rt);
		int mid=(l+r)>>1;
		if(L<=mid) update(ls,l,mid,L,R,c);
		if(R>mid) update(rs,mid+1,r,L,R,c);
	}
	inline int query(int rt,int l,int r,int p){
		if(l==r) return col[rt];
		push_down(rt);
		int mid=(l+r)>>1;
		if(p<=mid) return query(ls,l,mid,p);
		return query(rs,mid+1,r,p);
	}
}a[N][2];
inline int get_id(int x){
	return (x+1)/2; 
}
int main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	n=read(),k=read(),m=read();
	char opt[10];int la=0;
	for(int i=1,v=0;i<=m;i++) {
		scanf("%s",opt);
		if(opt[0]=='P') {
			cnt++;
			q[cnt].c=read()-1,q[cnt].x1=read()+1,q[cnt].y1=read()+1,q[cnt].x2=read()+1,q[cnt].y2=read()+1;
			pre[cnt]=la;la=cnt;
		}else if(opt[0]=='S') {
			ver[++v]=cnt;
		}else {int x=read();la=ver[x];}
	}
	int t=(opt[0]=='L')?la:cnt;cnt=0;
	while(t){
		tq[++cnt]=q[t];
		t=pre[t];
	}
	
	reverse(tq+1,tq+cnt+1);
	/*for(int i=1;i<=cnt;i++) {
		int p=0;
		for(int j=tq[i].x1;j<=tq[i].x2;j++){
			for(int l=tq[i].y1+p;l<=tq[i].y2;l+=2)
				b[j][l]=tq[i].c;
			p^=1;
		}
	}
	
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) printf("%d ",b[i][j]+1);
		puts("");
	}*/
	
	int mx=(n+1)/2;
	for(int i=1;i<=cnt;i++){
		int vr=(tq[i].y1&1),t=((tq[i].y2-tq[i].y1+1)&1)^1;
		int l1=get_id(tq[i].y1),r1=get_id(tq[i].y2-t);
		int l2=get_id(tq[i].y1+1),r2=get_id(tq[i].y2-(t^1));
		for(int j=tq[i].x1;j<=tq[i].x2;j+=2){
			a[j][vr].update(1,1,mx,l1,r1,tq[i].c);
			if(j+1<=tq[i].x2) a[j+1][vr^1].update(1,1,mx,l2,r2,tq[i].c);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",a[i][j&1].query(1,1,mx,(j+1)/2)+1);
		putchar('\n');
	}
	return 0;
}
/*
3 4 7
PAINT 2 0 0 1 1
SAVE
PAINT 3 1 1 2 2
SAVE
PAINT 4 0 2 0 2
LOAD 2
PAINT 4 2 0 2 0

*/
