#include<bits/stdc++.h>

const int MAXN = 805;
const int MAXM = 10001;

int siz;
long long vala[MAXN][MAXN],valb[MAXN][MAXN];
long long sa[MAXN][MAXN],sb[MAXN][MAXN],sum[MAXN][MAXN];

long long Solve(const int& y,const int& x){
    if(y<0 || x<0) return 0LL;
    
    if(sum[y][x] == -1){
        sum[y][x] = 0LL;
        for(int k=0;k<siz;k++) sum[y][x] += sa[y][k]*sb[k][x];
    } return sum[y][x];
}

signed main(void)
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);

    int totQuery;
    
    scanf("%d%d", &siz,&totQuery);
    for(int i=0;i<siz;i++)
        for(int j=0;j<siz;j++)
            scanf("%lld", vala[i]+j);
    for(int i=0;i<siz;i++)
        for(int j=0;j<siz;j++)
            scanf("%lld", valb[i]+j);

    //Init
    for(int k=0;k<siz;k++){
        sa[0][k] = vala[0][k];
        for(int j=1;j<siz;j++) sa[j][k] = sa[j-1][k] + vala[j][k];
    }
    for(int k=0;k<siz;k++){
        sb[k][0] = valb[k][0];
        for(int i=1;i<siz;i++) sb[k][i] = sb[k][i-1] + valb[k][i];
    }

    memset(sum,-1,sizeof(sum));
    int up,down,lft,rgt;
    while(totQuery--){
        scanf("%d%d%d%d", &up,&lft,&down,&rgt); --up; --lft; --down; --rgt;
        if(up>down) std::swap(up,down); if(lft>rgt) std::swap(lft,rgt);        
        printf("%lld\n", Solve(down,rgt)-Solve(up-1,rgt)-Solve(down,lft-1)+Solve(up-1,lft-1));
    }
    /*
    for(int i=0;i<siz;i++){
        for(int j=0;j<siz;j++)
            std::cout<<Solve(i,j)<<' ';
        std::cout<<std::endl;
        }*/
    
    return 0;
}
