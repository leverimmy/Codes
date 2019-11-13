#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))

const int MAXN = 5000+50;

long long D[MAXN];
long long val[MAXN],sum[MAXN];

std::vector<int> add[MAXN],del[MAXN];

std::priority_queue< int,std::vector<int>,std::greater<int> >que,delt;

signed main(void)
{
    freopen("shopping.in","r",stdin);
    freopen("shopping.out","w",stdout);
    
    int totLen,totArea,fr,to;

    scanf("%d%d", &totLen,&totArea);
    for(int i=1;i<=totLen;++i){ scanf("%lld", val+i); sum[i] = sum[i-1]+val[i]; }
    for(int i=0;i<totArea;++i){
        scanf("%d%d", &fr,&to);
        if(fr > to) std::swap(fr,to);
        add[fr].push_back(fr); del[to+1].push_back(fr);
    }

    for(int i=1;i<=totLen;i++){
        D[i] = D[i-1];

        for(int j=0;j<add[i].size();++j) que.push(add[i][j]);
        for(int j=0;j<del[i].size();++j) delt.push(del[i][j]);
        while(!que.empty() && !delt.empty() && que.top()==delt.top()){ que.pop(); delt.pop(); }
        
        for(int j=(que.empty()?INT_MAX:que.top());j<=i;j++)
            D[i] = std::max(D[i], D[j-1]+sqr(sum[i]-sum[j-1]));
    }

    printf("%lld\n", D[totLen]);
    
    return 0;
}
