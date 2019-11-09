#include <cstdio>
#include <iostream>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 200010;
const double INF = 999999999.0;
int n;
int p[N],r[N];
double ans[N];
int read(){
	char ch=getchar();
	int res=0,cf=1;
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			cf=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*cf;
}
int main(){
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	n=read();
	for(int i=1; i<=n; i++){
		p[i]=read();
		r[i]=read();
	}
	ans[1]=(double)r[1];
	for(int i=2; i<=n; i++){
		ans[i]=INF;
		double lastr=0;
		for(int j=i-1; j>=i-400 && j>=1; j--){
			if(ans[j]<=lastr){
				continue;
			}
			else{
				lastr=ans[j];
			}
			double x=(((double)p[i]-(double)p[j])*((double)p[i]-(double)p[j]))/(4.0*ans[j]);
			ans[i]=min(x, ans[i]);
		}
		ans[i]=min(ans[i], (double)r[i]);
	}
	for(int i=1; i<=n; i++){
		printf("%.3lf\n",ans[i]);
	}
	return 0;
}
