#include<bits/stdc++.h>

const long long MOD = 998244353LL;

long long D[1000][1000];

long long f(const int& up,const int& down){
    if(up>down || up<0 || down<0) return 0LL;
    if(D[up][down] != -1) return D[up][down];
    D[up][down] = up==down ? f(up-1,down-1) : 0LL;
    for(int i=1;i<=std::max(up,down);i++)
	(D[up][down] += f(up-i,down) + f(up,down-i)) %= MOD;
    return D[up][down] %= MOD;
}

struct Matrix{
    long long val[2][2];
    Matrix(){ memset(val,0,sizeof(val)); val[0][0] = val[1][1] = 1LL; }

    Matrix& Cls(void){ memset(val,0,sizeof(val)); return *this; }
    Matrix operator * (const Matrix& times) const {
	Matrix ans; ans.Cls();
	for(int i=0;i<2;i++)
	    for(int j=0;j<2;j++)
		for(int k=0;k<2;k++)
		    (ans.val[i][j] += val[i][k] * times.val[k][j]) %= MOD;
	return ans;
    } Matrix& operator *= (const Matrix& times){ return *this = *this * times; }
};
Matrix Pow(Matrix a,long long pows){
    Matrix ans;
    for(;pows>0;pows>>=1,a*=a)
	if(pows&1) ans *= a;
    return ans;
}

signed main(void)
{
    freopen("puzzle.in", "r",stdin);
    freopen("puzzle.out","w",stdout);
    
    memset(D,-1,sizeof(D)); D[0][0] = 1LL;

    int totCases,type; long long totLen;
    Matrix base,ret;
    base.Cls();
    base.val[0][0] = base.val[1][0] = base.val[0][1] = 1LL;

    scanf("%d%d", &totCases,&type);
    while(totCases--){
	scanf("%lld", &totLen);
	switch(type){
	case 1:
	    ret = Pow(base,totLen-1);
	    printf("%lld\n", ret.val[0][0]+ret.val[0][1]);
	    break;
	case 0:
	    printf("%lld\n", f(totLen,totLen));
	    break;
	default: assert(false); break;
	}
    }
    
    return 0;
}
