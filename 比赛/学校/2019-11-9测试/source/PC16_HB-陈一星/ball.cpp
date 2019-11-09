#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<set>
#include<queue>
#include<map>
#include<stack>
#define double long double
using namespace std;
const int M=220000;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
inline int read(void){
	int x=0,f=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
struct ball{
	double x,r;
	int id;
	double ans;
}p[M];
inline bool cmp(ball a,ball b){
	return a.x<b.x;	
}
inline bool cmpe(ball a,ball b){
	return a.id<b.id;	
}
vector<int>maxx;
int n;
double nx;
signed main(void){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) scanf("%Lf %Lf",&p[i].x,&p[i].r),p[i].id=i;
	sort(p+1,p+n+1,cmp);
	nx=0.0;
	for (int i=1;i<=n;i++){
		p[i].ans=p[i].r*1.0;
		for (int j=0;j<maxx.size();j++)
			p[i].ans=min(1.0*(p[i].x-p[maxx[j]].x)*(p[i].x-p[maxx[j]].x)/(4.0*p[maxx[j]].ans),p[i].ans);
		if (nx<p[i].x+p[i].ans) maxx.clear(),nx=p[i].x+p[i].ans;
		if (abs(nx-p[i].x-p[i].ans)<eps) maxx.push_back(i);
	}
	sort(p+1,p+n+1,cmpe);
	for (int i=1;i<=n;i++)
		printf("%.3Lf\n",p[i].ans);
	return 0;	
}
