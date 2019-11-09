#include<bits/stdc++.h>
#define double long double

const int MAXN=220000;
const int inf=0x3f3f3f3f;
const double eps=1e-9;

struct ball{
	double x,r; int id; double ans;
}p[MAXN];

inline bool cmp(ball a,ball b){
	return a.x<b.x;	
}
inline bool cmp2(ball a,ball b){
	return a.id<b.id;	
}

std::vector<int>max; int totNums;

signed main(void)
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	
	scanf("%d", &totNums);
	for(int i=1;i<=totNums;i++) scanf("%Lf%Lf",&p[i].x,&p[i].r),p[i].id=i;
	std::sort(p+1,p+totNums+1,cmp);
	
	double lb = 0;
	for(int i=1;i<=totNums;i++){
		p[i].ans=(double)p[i].r;
		for (int j=0;j<max.size();j++)
			p[i].ans=std::min((double)(p[i].x-p[max[j]].x)*(p[i].x-p[max[j]].x) / (4.0*p[max[j]].ans), p[i].ans);
			
		if (lb<p[i].x+p[i].ans) max.clear(),lb=p[i].x+p[i].ans;
		if (abs(lb-p[i].x-p[i].ans) < eps) max.push_back(i);
	}
	
	std::sort(p+1,p+totNums+1,cmp2);
	for(int i=1;i<=totNums;i++) printf("%.4Lf\n",p[i].ans);
		
	return 0;	
}
