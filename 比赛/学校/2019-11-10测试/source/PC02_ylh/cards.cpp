#include <bits/stdc++.h>
#define ll long long
int a,b;
ll ans=-((ll)1<<(ll)60);
ll sqr(int x){return (ll)x*x;}
int main(){
	freopen("cards.in","r",stdin);
	freopen("cards.out","w",stdout);
	scanf("%d%d",&a,&b);
	if (b==0){printf("%lld\n",sqr(a));for(int i=1;i<=a;++i)printf("o");return 0;}
	if (a==0){printf("%lld\n",-sqr(b));for(int i=1;i<=b;++i)printf("x");return 0;}
	int max=0;
	for(int i=1;i<=a;++i){
		int d=a-i+2;
		ll p2=sqr(b/d)*(d-b%d)+sqr(b/d+1)*(b%d);
		if (sqr(i)+a-i-p2>ans)max=i;
		ans=std::max(ans,sqr(i)+a-i-p2);
	}printf("%lld\n",ans,max);
	int flag=0;
	for(int i=1;i<=a-max+2;++i){
		int d=a-max+2;
		if (i<=b%d){
			for(int j=1;j<=b/d+1;++j)printf("x");
			if (i!=d){
				if (!flag){for(int i=1;i<=max;++i)printf("o");flag=1;}
				else printf("o");
			}
		} else {
			for(int j=1;j<=b/d;++j)printf("x");
			if (i!=d){
				if (!flag){for(int i=1;i<=max;++i)printf("o");flag=1;}
				else printf("o");
			}
		}
	}
	return 0;
}
