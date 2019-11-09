#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
struct node{
	long double x,r;
}a[200100];
stack <node> S;
int n;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i<=n;i++){
		double x,r;
		scanf("%lf%lf",&x,&r);
		while (!S.empty()){
			node tt = S.top();
			r = min(r,(x - (double)tt.x)*(x - (double)tt.x)/(double)(4*(double)tt.r));
			if (r >= tt.r) S.pop();
			else break;
		}
		S.push((node){x,r});
		printf("%.4lf\n",r);
	}
	return 0;
}
