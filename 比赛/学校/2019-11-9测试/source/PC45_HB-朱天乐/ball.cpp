#include <iostream>
using namespace std;
int n;
double x[200005];
double r[200005];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>r[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			r[i]=min(r[i],(x[i]-x[j])*(x[i]-x[j])/(4*r[j]));
		}
	}
	for(int i=1;i<=n;i++){
		printf("%.3f\n",r[i]);
	}
	return 0;
}
