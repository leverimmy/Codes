#include <bits/stdc++.h>
#define ll long long
#define maxn 4000005
int n,vis[maxn]={0},hd=1,tl=0,hd2=1,tl2=0;
ll a[maxn];
__int128 ans=0;

void prt(int x){
	for(int i=9;i>=0;i--)if (i<=x){printf("%d",i);return;}
}

void print(__int128 x){
	if (x<10){prt(x%10);return ;}
	print(x/10);prt(x%10);
}
	

int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
//	std::random_shuffle(a+1,a+n+1);
	for(int i=1;i<n;++i){
		__int128 tmp=1;
		tmp*=a[i];tmp*=a[i+1];
		ans+=tmp;a[i+1]+=a[i];
	}
	print(ans);
	return 0;
}
