#include<bits/stdc++.h>

const int MAXN = 67000;

int totNums;
std::vector<int> G[MAXN];
int in[MAXN],orgin[MAXN];

int Solve(const int& s){
    for(int i=0;i<totNums;i++) in[i] = orgin[i];

    int cnt = -1,nowAt;
    std::queue<int> que; que.push(s);
    while(!que.empty()){
        nowAt = que.front(); que.pop(); ++cnt;
        for(int i=0;i<G[nowAt].size();i++)
            if(--in[G[nowAt][i]] == 0)
                que.push(G[nowAt][i]);
    } return cnt;
}

signed main(void)
{
    freopen("catas.in","r",stdin);
    freopen("catas.out","w",stdout);
    
    int tot,targ;

    scanf("%d", &totNums);
    for(int i=0;i<totNums;i++)
        while(true){
            scanf("%d", &targ);
            if(targ == 0) break;
            G[targ-1].push_back(i);
            orgin[i]++;
        }

    for(int i=0;i<totNums;i++) printf("%d\n", Solve(i));
    
    return 0;
}
