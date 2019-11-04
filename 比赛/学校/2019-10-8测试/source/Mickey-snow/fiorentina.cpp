#include<bits/stdc++.h>

const long long MOD = 998244353LL;
const int MAXN = 10000;

long long D[2][MAXN];

signed main(void)
{
    freopen("fiorentina.in","r",stdin);
    freopen("fiorentina.out","w",stdout);
    
    int n,p;

    std::cin>>n>>p;
    **D = 1;

    int last = 1,now = 0;
    for(int i=1;i<=n;++i){
	std::swap(last,now);
	for(int j=p;j>=0;j--){
	    D[now][j] = D[last][j];
	    if(j >= i) (D[now][j] += D[last][j-i]) %= MOD;
	}
    }

    std::cout<<D[now][p]<<std::endl;
    
    return 0;
}
