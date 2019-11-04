#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384
const int N=100005;
int n,m;
double x[N],y[N];
struct Mat{
	double a00,a01,a02,a10,a11,a12,a20,a21,a22;
	Mat(double x1=1,double x2=0,double x3=0,double x4=0,double x5=1,double x6=0,double x7=0,double x8=0,double x9=1){
		a00=x1,a01=x2,a02=x3;
		a10=x4,a11=x5,a12=x6;
		a20=x7,a21=x8,a22=x9;
	}
};
Mat operator * (const Mat & a, const Mat & b){
		Mat c(0,0,0,0,0,0,0,0,0);
		c.a00=a.a00*b.a00+a.a01*b.a10+a.a02*b.a20;
		c.a01=a.a00*b.a01+a.a01*b.a11+a.a02*b.a21;
		c.a10=a.a10*b.a00+a.a11*b.a10+a.a12*b.a20;
		c.a11=a.a10*b.a01+a.a11*b.a11+a.a12*b.a21;
		c.a20=a.a20*b.a00+a.a21*b.a10+a.a22*b.a20;
		c.a21=a.a20*b.a01+a.a21*b.a11+a.a22*b.a21;
		c.a22=a.a20*b.a02+a.a21*b.a12+a.a22*b.a22;
		return c;
	}
Mat tag[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void pushdown(int rt){
	tag[ls]=tag[ls]*tag[rt];
	tag[rs]=tag[rs]*tag[rt];
	tag[rt]=Mat();
}
inline void modify(int rt,int l,int r,int L,int R,Mat &c){
	if(L<=l&&r<=R) {
		tag[rt]=tag[rt]*c;
		return;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(L<=mid) modify(ls,l,mid,L,R,c);
	if(R>mid) modify(rs,mid+1,r,L,R,c); 
}
inline void query(int rt,int l,int r){
	if(l==r) {
		Mat c(x[l],y[l],1,0,0,0,0,0,0);
		c=c*tag[rt];
		printf("%.2lf %.2lf\n",c.a00,c.a01);
		return;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	query(ls,l,mid);query(rs,mid+1,r);
}
int main(){
	freopen("madrid.in","r",stdin);
	freopen("madrid.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
	scanf("%d",&m);char opt[10];
	int l,r;double p,q;Mat c;
	while(m--){
		scanf("%s",opt);scanf("%d%d",&l,&r);
		if(opt[0]=='M') {
			scanf("%lf%lf",&p,&q);
			c=Mat(1,0,0,0,1,0,p,q,1);
		}else if(opt[0]=='X'){
			c=Mat(1,0,0,0,-1,0,0,0,1);
		}else if(opt[0]=='Y'){
			c=Mat(-1,0,0,0,1,0,0,0,1);
		}else if(opt[0]=='O'){
			c=Mat(0,1,0,1,0,0,0,0,1);
		}else {
			scanf("%lf",&p);p=p*PI/180;
			c=Mat(cos(p),sin(p),0,-sin(p),cos(p),0,0,0,1);
		}
		modify(1,1,n,l,r,c);
	}
	query(1,1,n);
	return 0;
}
/*
3 
1 2 
-2 2.5 
0 -3 
5 
X 1 3 
Y 2 3
O 1 2
M 1 3 3 6 
R 1 3 90
*/
