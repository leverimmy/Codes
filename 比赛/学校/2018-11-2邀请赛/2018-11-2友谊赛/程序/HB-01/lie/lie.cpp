//
//  main.cpp
//  lie
//
//  Created by 童维希 on 2018/11/2.
//  Copyright © 2018 童维希. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <string>
#define maxn 500001
using namespace std;
int n,cnt,head[maxn],dp[maxn];
struct edge{
    int to,nxt;
}edges[maxn];
void add(int u,int v){
    cnt++;
    edges[cnt].to=v;
    edges[cnt].nxt=head[u];
    head[u]=cnt;
}
typedef pair<int, int> twxp;
map<twxp,int>mp;
int main() {
    freopen("lie.in", "r", stdin);
    freopen("lie.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        if (x+y>=n) {
            continue;
        }
        x=x+1;
        y=n-y;
        twxp a;
        a.first=x;
        a.second=y;
        mp[a]++;
        if (mp[a]==1) {
            add(y, x);
        }
    }
    /*
    for (int k=1; k<=n; k++) {
        for (int u=1; u<=n; u++) {
            for (int i=head[u]; i; i=edges[i].nxt) {
                int v=edges[i].to;
                twxp a;
                a.first=v;
                a.second=u;
                dp[k][u]=max(dp[k-1][u],dp[k-1][v-1]+min(u-v+1,mp[a]));
            }
        }
    }
     */
    for (int u=1; u<=n; u++) {
        dp[u]=dp[u-1];
        for (int i=head[u]; i; i=edges[i].nxt) {
            int v=edges[i].to;
            twxp a;
            a.first=v;
            a.second=u;
            dp[u]=max(dp[u],dp[v-1]+min(u-v+1,mp[a]));
        }
    }
    printf("%d\n",n-dp[n]);
    //printf("%d\n",n-dp[k][n]);
    return 0;
}
