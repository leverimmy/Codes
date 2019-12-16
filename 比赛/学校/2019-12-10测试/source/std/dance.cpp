#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<random>
#include<cmath>
#define ll long long
#define x1 _x1
#define y1 _y1
#define x2 _x2
#define y2 _y2
#define fr(i,x,y) for(int i=(x);i<=(y);i++)
#define rf(i,x,y) for(int i=(x);i>=(y);i--)
#define frl(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;
const int N=300003;
int n,m;
ll b[N],s[N];
struct data{
	int num,x;
}st[N];  //这是一个栈，维护凸折线上的点
int L;

inline int sign(ll &x){
	if (x>0) return 1;
	if (x<0) return -1;
	return 0;
}

inline int mul(ll x1,ll y1,ll x2,ll y2){  //这个是判断叉积是否>0的
	int w1=sign(x1)*sign(y2),w2=sign(y1)*sign(x2);
	if (w1!=w2) return w1>w2;
	if (w1==0) return 0;
	return (long double)x1*y2>(long double)y1*x2;
}

void read(int &x){ scanf("%d",&x); }
void read(ll &x){ scanf("%lld",&x); }

void chkmin(ll &x,ll y){ if (y<x) x=y; }

inline ll cal(data q,int w){ //计算A[q.x]
	return b[w]-b[q.num]+1ll*(q.x-1)*(s[w]-s[q.num]);
}

void AddPoint(int w,int x){
	if (cal(st[L],w)==0) return;
	ll y=cal((data){w,x},w);
	while(L>=2){
		if (mul(st[L].x-st[L-1].x,cal(st[L],w)-cal(st[L-1],w),
		x-st[L].x,y-cal(st[L],w))) break;
		L--;
	}
	st[++L]=(data){w,x};
}

void PopBack(int w){
	while(L>=2&&cal(st[L],w)>=cal(st[L-1],w)) L--;
}

int main(){
freopen("dance.in","r",stdin);
  freopen("dance.out","w",stdout);
	read(n);read(m);
	int tp;ll x,y;
	st[L=1]=(data){0,1};
	fr(i,1,m){
		b[i]=b[i-1];s[i]=s[i-1];
		read(tp);read(x);
		if (tp==1){
			b[i]=s[i]=0;
			st[L=1]=(data){i,1};
			n+=x;
		}else if (tp==2){
			AddPoint(i,n+1);
			n+=x;
		}else{
			read(y);
			b[i]+=x;s[i]+=y;
			PopBack(i);
		}
		printf("%d %lld\n",st[L].x,cal(st[L],i));
	}
	return 0;
}
