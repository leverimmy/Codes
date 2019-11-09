#include<bits/stdc++.h>
#define Polaris_Bane INT_MAX

const int MAXN = 100+50;

int val[MAXN]; double sum[MAXN];
double D[MAXN][MAXN];

bool Cmp(const int& a,const int& comp){ return a>comp; }

signed main(void)
{
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	
	int totNums,totDiv,tot=0;
	
	scanf("%d%d", &totNums,&totDiv);
	for(int i=1;i<=totNums;i++){ scanf("%d", val+i); tot += val[i]; }
	std::sort(val+1,val+1+totNums,Cmp);
	for(int i=1;i<=totNums;i++) sum[i] = sum[i-1]+((double)val[i])/tot;
	
	for(int i=1;i<=totNums;i++) D[i][1] = sum[i]*i;
	for(int div=2;div<=totDiv;++div)
		for(int i=div;i<=totNums;i++){
			D[i][div] = Polaris_Bane;
			for(int k=div-1;k<i;k++)
				D[i][div] = std::min(D[i][div], D[k][div-1]+i*(sum[i]-sum[k]));
		}
	
	printf("%.4lf\n", D[totNums][totDiv]);
	
	return 0;
}
