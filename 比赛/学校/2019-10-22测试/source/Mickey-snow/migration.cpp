#include<bits/stdc++.h>

const int MAXN = (int)3e5;

std::vector<int> G[MAXN];
int arr[MAXN]; bool exist[MAXN];

std::stack<bool> S;

int up[MAXN];
int FindTop(const int& nowAt){
    return up[nowAt]==nowAt ? nowAt : (up[nowAt]=FindTop(up[nowAt]));
}
int Unity(int a,int b){
    a = FindTop(a); b = FindTop(b);
    if(a == b) return 0;
    up[a] = b;
    return 1;
}

signed main(void)
{
    freopen("migration.in","r",stdin);
    freopen("migration.out","w",stdout);
    
    int totPoints,totEdges,totBlk,targ,fr,to;

    scanf("%d%d", &totPoints,&totEdges);
    for(int i=0;i<totEdges;i++){
        scanf("%d%d", &fr,&to);
        G[fr].push_back(to); G[to].push_back(fr);
    }
    for(int i=0;i<totPoints;i++) scanf("%d", arr+i);
    
    totBlk = 0;
    for(int i=0;i<=totPoints;i++) up[i] = i;
    for(int i=totPoints-1;i>=0;i--){
        exist[arr[i]] = true; ++totBlk;
        for(int j=0;j<G[arr[i]].size();j++){
            const int& it = G[arr[i]][j];
            if(exist[it]) totBlk -= Unity(arr[i], it);
        } S.push(totBlk <= 1);
    }

    while(!S.empty()){
        puts(S.top() ? "YES" : "NO");
        S.pop();
    }
    
    return 0;
}
