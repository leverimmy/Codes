#include<bits/stdc++.h>
#define eps 1e-8
using namespace std;
struct node{
	double x;
	double r;
}in[200010];
double cal(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int n;
double lx,ly,lr;
double ans[200010];
int check(double k,int ind){
	double x=in[ind].x,y=k;
	double dis;
	int f=1;
	for(int i=1;i<ind;i++){
		dis=(in[i].x,ans[i],x,y);
		if(dis-k-ans[i]>eps) f=1;
		else f=0;
	}
	if(f) return 1;
	else return 0;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&in[i].x,&in[i].r);
	}
	lx=in[1].x,ly=in[1].r,lr=in[1].r;
	ans[1]=in[1].r;
	if(n<=2000){
		for(int i=2;i<=n;i++){
			double k=in[i].r;
			for(int j=1;j<i;j++){
				double k1=in[i].x-in[j].x;
				k=min(k,k1*k1/ans[j]/4);
			}
			ans[i]=k;
		}
	}
	else{
		for(int i=2;i<=n;i++){
			double k=in[i].r;
			for(int j=max(j-500,1);j<i;j++){
				double k1=in[i].x-in[j].x;
				k=min(k,k1*k1/ans[j]/4);
			}
			ans[i]=k;
		}		
	}
	for(int i=1;i<=n;i++){
		printf("%.3lf\n",ans[i]);
	}
} 

