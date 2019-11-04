#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
struct Mat{
	ll a[2][2];
	Mat(){memset(a,0,sizeof(a));}
	Mat operator * (const Mat & b){
		Mat c;
		for(int k=0;k<2;k++)
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j]%mod)%mod;
		return c;
	}
};
inline Mat qpow(Mat a,ll b){
	Mat res;res.a[0][0]=res.a[1][1]=1;
	for(;b;b>>=1,a=a*a) if(b&1) res=res*a;
	return res;
}
Mat a,b;
int main(){
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	int T,type;scanf("%d%d",&T,&type);
	if(type==1) {
		a.a[0][0]=a.a[0][1]=a.a[1][0]=1;
		b.a[0][0]=2,b.a[1][0]=1;
	}else {
		a.a[0][0]=5,a.a[0][1]=mod-3,a.a[1][0]=1;
		b.a[0][0]=7,b.a[1][0]=2;
	}
	while(T--){
		ll n;scanf("%lld",&n);
		printf("%lld\n",(qpow(a,n-1)*b).a[1][0]);
	}
	return 0;
}
