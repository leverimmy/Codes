#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<queue>
#include<map>
#define M 600100
#define inf 0x3f3f3f3f
#define LL long long
using namespace std;
const double pie=acos(-1);
int n,m;
struct node{
	double x,y;
}t[M];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while (isdigit(s))
	{
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*f;
}
inline void add(int l,int r,double p,double q){
	for (int i=l;i<=r;++i) t[i].x+=p,t[i].y+=q;
}
inline void reverse_x(int l,int r){
	for (int i=l;i<=r;++i) t[i].y=-t[i].y;
}
inline void reverse_y(int l,int r){
	for (int i=l;i<=r;++i) t[i].x=-t[i].x;
}
inline void reverse_to(int l,int r){
	for (int i=l;i<=r;++i) swap(t[i].x,t[i].y);
}
inline void rotate_degree(int l,int r,double a){
	double sina=sin(a*pie/180),cosa=cos(a*pie/180);
	for (int i=l;i<=r;++i){
		double x=t[i].x,y=t[i].y;
		t[i].x=cosa*x-sina*y;
		t[i].y=sina*x+cosa*y;
	}
}
signed main(void)
{
	freopen("madrid.in","r",stdin);
	freopen("madrid.out","w",stdout);
	n=read();
	for (int i=1;i<=n;++i) scanf("%lf %lf",&t[i].x,&t[i].y);
	m=read();
	for (int i=1;i<=m;i++){
		char s;cin>>s;
		int l=read(),r=read();
		if (s=='M'){
			double p,q;scanf("%lf %lf",&p,&q);
			add(l,r,p,q);
		} 
		if (s=='X') reverse_x(l,r);
		if (s=='Y') reverse_y(l,r);
		if (s=='O') reverse_to(l,r);
		if (s=='R'){
			double a;scanf("%lf",&a);
			rotate_degree(l,r,a);
		}
	}
	for (int i=1;i<=n;i++) printf("%.2lf %.2lf\n",t[i].x,t[i].y);
    return 0;
}

