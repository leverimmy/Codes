#include<bits/stdc++.h>

const int MAXN = 50050;
const int MAXK = 205;

std::vector<int> G[MAXN];
bool vis[MAXN];

long long ans;

int mod[MAXK],sumcnt[MAXK],k,dmod[MAXK],dsumcnt[MAXK];
void Calc(const int& nowAt, int nowmod, int nowcnt, const int& fa = 0){
    if(nowmod >= k){
        nowmod -= k; ++nowcnt;
    }

    ans += nowcnt + (nowmod+k-1)/k;
    for(int i=0;i<k;i++){
        if(mod[i]>0) ans += nowcnt+sumcnt[i];
        ans += mod[i]*((nowmod+i+k-1)/k);
    }
    ++dmod[nowmod]; dsumcnt[nowmod] += nowcnt;

    for(int i=0;i<G[nowAt].size();i++){
        const int it = G[nowAt][i];
        if(it!=fa && !vis[it])
            Calc(it, nowmod+1,nowcnt, nowAt);
    }
}
int S,siz[MAXN],maxsiz[MAXN],imp;
void Find(const int& nowAt, const int& fa = 0){
    maxsiz[nowAt] = siz[nowAt] = 1;
    for(int i=0;i<G[nowAt].size();i++)
        if(!vis[G[nowAt][i]] && fa!=G[nowAt][i]){
            Find(G[nowAt][i], nowAt);
            siz[nowAt] += siz[G[nowAt][i]];
            maxsiz[nowAt] = std::max(maxsiz[nowAt], siz[G[nowAt][i]]);
        }
    maxsiz[nowAt] = std::max(maxsiz[nowAt], S-siz[nowAt]);
    if(maxsiz[nowAt] < maxsiz[imp]) imp = nowAt;
}
void Dfs(const int nowAt){
    vis[nowAt] = true;
    memset(mod,0,sizeof(mod)); memset(sumcnt,0,sizeof(sumcnt));
    for(int i=0;i<G[nowAt].size();i++){
        const int it = G[nowAt][i];
        if(!vis[it]){
            memset(dmod,0,sizeof(dmod)); memset(dsumcnt,0,sizeof(dsumcnt));
            Calc(it,1,0,nowAt);
            for(int i=0;i<k;i++){
                mod[i] += dmod[i]; sumcnt[i] += dsumcnt[i];
            }
        }
    }

    int mks = S;
    for(int i=0;i<G[nowAt].size();i++){
        const int it = G[nowAt][i];
        if(!vis[it]){
            imp = 0;
            if(siz[it] > siz[nowAt]) S = mks - siz[nowAt];
            else S = siz[it];
            Find(it);
            Dfs(imp);
        }
    }
}

signed main(void)
{
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    
    int totVertex,fr,to;

    scanf("%d%d", &totVertex,&k);
    for(int i=1;i<totVertex;i++){
        scanf("%d%d", &fr,&to);
        G[to].push_back(fr); G[fr].push_back(to);
    }

    S = totVertex; *maxsiz = *siz = INT_MAX; imp = 0; Find(1);
    Dfs(imp);

    printf("%lld\n", ans);
    
    return 0;
}
