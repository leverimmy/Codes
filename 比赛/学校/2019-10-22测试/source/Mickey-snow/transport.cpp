#include<bits/stdc++.h>

signed main(void)
{
    freopen("transport.in","r",stdin);
    freopen("transport.out","w",stdout);
    
#define abs(x) (((x)<0) ? (-(x)) : (x))
    const int MAXN = 600;

    int totPoints,totSkip;
    long long D[MAXN][MAXN]={},x[MAXN]={},y[MAXN]={};

    scanf("%d%d", &totPoints,&totSkip);
    for(int i=0;i<totPoints;i++){
        scanf("%lld%lld", x+i,y+i);
        if(i!=0 && x[i]==x[i-1] && y[i]==y[i-1]){ --i; --totPoints; }
    }

    memset(D,0x7f,sizeof(D)); D[0][0] = 0;
    for(int i=1;i<totPoints;i++){
        for(int j=0;j<=totSkip;j++)
            D[i][j] = D[i-1][j] + abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]);
        for(int k=std::max(0,i-totSkip-1);k<i-1;k++)
            for(int j=(i-k-1);j<=totSkip;j++)
                D[i][j] = std::min(D[i][j], D[k][j-(i-k-1)] + abs(x[i]-x[k])+abs(y[i]-y[k]));
    }

    printf("%lld\n", D[totPoints-1][std::min(totPoints-2,totSkip)]);
    
    return 0;
}
