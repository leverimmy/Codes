#include <bits/stdc++.h>
#define maxn 100005
double pi=3.1415926535897932384;
int n,q1,l,r;
char opt[4];
double p,q,a,x[maxn],y[maxn];

struct matrix {
	double a[4][4];int r,c;
	void init(int r1,int c1,double a1,double a2,double a3,double a4,double a5,double a6,double a7,double a8,double a9){
		r=r1;c=c1;a[1][1]=a1;a[1][2]=a2;a[1][3]=a3;a[2][1]=a4;a[2][2]=a5;a[2][3]=a6;a[3][1]=a7;a[3][2]=a8;a[3][3]=a9;
	}void mul(matrix b){
		matrix c1;c1.init(r,b.c,0,0,0,0,0,0,0,0,0);
	
		c1.a[1][1]+=a[1][1]*b.a[1][1];
		c1.a[1][2]+=a[1][1]*b.a[1][2];
		c1.a[1][3]+=a[1][1]*b.a[1][3];
		c1.a[1][1]+=a[1][2]*b.a[2][1];
		c1.a[1][2]+=a[1][2]*b.a[2][2];
		c1.a[1][3]+=a[1][2]*b.a[2][3];
		c1.a[1][1]+=a[1][3]*b.a[3][1];
		c1.a[1][2]+=a[1][3]*b.a[3][2];
		c1.a[1][3]+=a[1][3]*b.a[3][3];
		c1.a[2][1]+=a[2][1]*b.a[1][1];
		c1.a[2][2]+=a[2][1]*b.a[1][2];
		c1.a[2][3]+=a[2][1]*b.a[1][3];
		c1.a[2][1]+=a[2][2]*b.a[2][1];
		c1.a[2][2]+=a[2][2]*b.a[2][2];
		c1.a[2][3]+=a[2][2]*b.a[2][3];
		c1.a[2][1]+=a[2][3]*b.a[3][1];
		c1.a[2][2]+=a[2][3]*b.a[3][2];
		c1.a[2][3]+=a[2][3]*b.a[3][3];
		c1.a[3][1]+=a[3][1]*b.a[1][1];
		c1.a[3][2]+=a[3][1]*b.a[1][2];
		c1.a[3][3]+=a[3][1]*b.a[1][3];
		c1.a[3][1]+=a[3][2]*b.a[2][1];
		c1.a[3][2]+=a[3][2]*b.a[2][2];
		c1.a[3][3]+=a[3][2]*b.a[2][3];
		c1.a[3][1]+=a[3][3]*b.a[3][1];
		c1.a[3][2]+=a[3][3]*b.a[3][2];
		c1.a[3][3]+=a[3][3]*b.a[3][3];
		for(register int i=1;i<=3;++i)for(register int j=1;j<=3;++j)a[i][j]=c1.a[i][j];
	}void print(){
		for(int i=1;i<=r;++i){
			printf("|");
			for(int j=1;j<=c;++j){
				printf("%.2f ",a[i][j]);
			}printf("|\n");
		}
	}
};

struct segmentTree {
	matrix tag[maxn<<2];
	int vis[maxn<<2]={0};
	inline void pushdown(int rt){
		if (!vis[rt])return;
		if (!vis[rt<<1]){vis[rt<<1]=1;tag[rt<<1]=tag[rt];}
		else tag[rt<<1].mul(tag[rt]);
		if (!vis[rt<<1|1]){vis[rt<<1|1]=1;tag[rt<<1|1]=tag[rt];}
		else tag[rt<<1|1].mul(tag[rt]);
		vis[rt]=0;
	}
	void modify(int l,int r,int L,int R,matrix m,int rt){
		if (l>R||r<L)return;
		if (l<=L&&R<=r){
			if (!vis[rt]){vis[rt]=1;tag[rt]=m;}
			else tag[rt].mul(m);
			return;
		}pushdown(rt);
		modify(l,r,L,(L+R)>>1,m,rt<<1);
		modify(l,r,((L+R)>>1)+1,R,m,rt<<1|1);
	}void dfs(int u,int l,int r){
		if (l==r){
			matrix mt;mt.init(1,3,x[l],y[l],1,0,0,0,0,0,0);
			if (vis[u])mt.mul(tag[u]);
			printf("%.2f %.2f\n",mt.a[1][1],mt.a[1][2]);
			return;
		}pushdown(u);
		dfs(u<<1,l,(l+r)>>1);dfs(u<<1|1,((l+r)>>1)+1,r);
	}
}sgt;

double rad(double x){
	return x*pi/(double)180;
}

int main(){
	freopen("madrid.in","r",stdin);
	freopen("madrid.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lf%lf",&x[i],&y[i]);
	scanf("%d",&q1);
	while(q1--){
		scanf("%s%d%d",&opt,&l,&r);
		matrix m;
		if (opt[0]=='M'){
			scanf("%lf%lf",&p,&q);
			m.init(3,3,1,0,0,0,1,0,p,q,1);
		}
		if (opt[0]=='X')m.init(3,3,1,0,0,0,-1,0,0,0,1);
		if (opt[0]=='Y')m.init(3,3,-1,0,0,0,1,0,0,0,1);
		if (opt[0]=='O')m.init(3,3,0,1,0,1,0,0,0,0,1);
		if (opt[0]=='R'){
			scanf("%lf",&a);a=rad(a);
			m.init(3,3,cos(a),sin(a),0,-sin(a),cos(a),0,0,0,1);
		}sgt.modify(l,r,1,n,m,1);
	}matrix m;m.init(3,3,1,0,0,0,1,0,0,0,1);
	sgt.dfs(1,1,n);
	return 0;
}




