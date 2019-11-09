#include <bits/stdc++.h>
#define maxn 200005
const double eps=1e-9;
int n,stk[maxn],tp=0;
double x[maxn],lim[maxn],r[maxn];
double calc(int i,int j){
	double d=(x[i]-x[j])/2;
	return d*d/r[j]; 
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lf%lf",&x[i],&lim[i]);
	r[1]=lim[1];stk[++tp]=1;
	for(int i=2;i<=n;++i){
		r[i]=lim[i];
		for(int j=1;j<=tp&&j<=20;++j)if (r[stk[j]]>eps)r[i]=std::min(r[i],calc(i,stk[j]));
		for(register int j=tp;j>=1&&tp-j<=40;j--)if (r[stk[j]]>eps)r[i]=std::min(r[i],calc(i,stk[j]));
		while (tp&&r[i]>r[stk[tp]])tp--;
		stk[++tp]=i;
	}for(int i=1;i<=n;++i)printf("%.5f\n",r[i]);
	return 0;
}
