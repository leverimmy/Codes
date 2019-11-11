#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
ll a,b; 
ll ans=-1e18;
int main(){
	freopen("cards.in","r",stdin);
	freopen("cards.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	if(a==0) {
		printf("%lld\n",-b*b);
		for(int i=1;i<=a+b;i++) putchar('x');
		return 0;
	}
	if(b==0){
		printf("%lld\n",a*a);
		for(int i=1;i<=a+b;i++) putchar('o');
		return 0;
	}
	if(b==1) {
		printf("%lld\n",a*a-1);putchar('x');
		for(int i=1;i<=a;i++) putchar('o');
		return 0;
	}
	for(int i=0;i<=a&&i+2<=b;i++) {
		ll x=b/(i+2),y=x+1;
		ll ny=b%(i+2),nx=i+2-ny;
		ans=max(ans,(a-i)*(a-i)+i-(x*x*nx+y*y*ny));
	}
	printf("%lld\n",ans);
	for(int i=0;i<=a&&i+2<=b;i++) {
		ll x=b/(i+2),y=x+1;
		ll ny=b%(i+2),nx=i+2-ny;
		ll rans=(a-i)*(a-i)+i-(x*x*nx+y*y*ny);
		if(ans==rans){
			int ni=i;
			while(nx>0) {
				for(int j=1;j<=x;j++) putchar('x');
				nx--;
				if(nx==0) break;
				if(ni>0) putchar('o'),ni--;
				else {
					for(int j=1;j<=a-i;j++) putchar('o');
				}
			}
			
			while(ny>0) {
				if(ni>0) putchar('o'),ni--;
				else {
					for(int j=1;j<=a-i;j++) putchar('o');
				}
				for(int j=1;j<=y;j++) putchar('x');
				ny--;
			}
			return 0;
		}
	}
	return 0;
}
