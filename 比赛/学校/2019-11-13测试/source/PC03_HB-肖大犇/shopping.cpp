#include<bits/stdc++.h>
using namespace std;
const int N=500005;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s; 
}
typedef long long ll;
int n,m;
int a[N],b[N];
ll f[N],sum[N];
inline ll sqr(ll x){return x*x;}
int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=m;i++){
		int l=read(),r=read();
		b[l]=max(b[l],r);
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=b[i];j++)
			b[j]=max(b[j],b[i]);
	for(int i=1;i<=n;i++){
		f[i]=max(f[i],f[i-1]);
		for(int j=i;j>=1;j--){
			if(!b[j]) continue;
			if(b[j]<=i) {
				f[i]=max(f[i],f[j-1]+sqr(sum[b[j]]-sum[j-1]));
			}else f[i]=max(f[i],f[j-1]+sqr(sum[i]-sum[j-1]));
		}
	}
	printf("%lld",f[n]);
	return 0;
}
