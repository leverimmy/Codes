#include<bits/stdc++.h>
using namespace std;
const double e=1e-18; 
int n,r,m;
char ch;
double x;
int main(){
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
	while(1){
		scanf("%lf",&x);
		if(fabs(x-0)<=e) break;
		double t=2;
		double ans=0;
		while(1){
			ans+=(double)(1/t);
			if(ans-x>=e){
				break;
			}
			t+=1;
		}
		printf("%.0lf card(s)\n",t-1);
	}
}
