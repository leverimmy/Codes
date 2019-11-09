#include<bits/stdc++.h>
using namespace std;
int n;
struct balloon{
	double pos,r,lim;
}b[200010];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lf%lf",&b[i].pos,&b[i].lim),b[i].r=2147483640;
	if(n<=2000){
		b[1].r=b[1].lim;
		printf("%.3lf\n",b[1].r);
		for(int i=2;i<=n;++i){
			for(int j=1;j<i;++j){
				b[i].r=min(b[i].r,(((b[i].pos-b[j].pos)*(b[i].pos-b[j].pos)))/(4*b[j].r));
			}
			b[i].r=min(b[i].r,b[i].lim);
			printf("%.3lf\n",b[i].r);
		}
		return 0;
	}
	b[1].r=b[1].lim;
	printf("%.3lf\n",b[1].r);
	for(int i=2;i<=n;++i){
		for(int j=max(1,i-10);j<i;++j){
			b[i].r=min(b[i].r,(((b[i].pos-b[j].pos)*(b[i].pos-b[j].pos)))/(4*b[j].r));
		}
		b[i].r=min(b[i].r,b[i].lim);
		printf("%.3lf\n",b[i].r);
	}
	return 0;
}
