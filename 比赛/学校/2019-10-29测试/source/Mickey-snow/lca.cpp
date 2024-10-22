#include<bits/stdc++.h>

#define MAXNODE 100050

std::vector<int> G[MAXNODE];

int up[MAXNODE][20];
int depth[MAXNODE], root;

void dfs(const int rootNow, const int &fa = -1) {
    depth[rootNow] = depth[fa] + 1;
    memset(up[rootNow], -1, sizeof(up[rootNow])); *up[rootNow] = fa;

    for (int i = 1; i < 20; i++)
        up[rootNow][i] = up[up[rootNow][i - 1]][i - 1];

    for(int i=0;i<G[rootNow].size();i++)
        if(depth[G[rootNow][i]] == -1)
            dfs(G[rootNow][i], rootNow);
}

int LCA(int a, int b) {
    if (depth[a] < depth[b])std::swap(a, b); 

    for (int x = 19; x >= 0; x--)
        if (depth[a] - (1 << x) >= depth[b])
            a = up[a][x];

    if (a == b)return a;

    for (int x = 19; x >= 0; x--)
        if (up[a][x] != -1 && up[a][x] != up[b][x]) {
            a = up[a][x]; b = up[b][x];
        }

    return up[a][0];
}

int main()
{
    freopen("lca.in","r",stdin);
    freopen("lca.out","w",stdout);
    
    memset(depth, -1, sizeof(depth));

    int totNode, totQuery, fr, to, fa, last_ans=0;
	
    //Read
    scanf("%d", &totNode);
    for (int i = 1; i <= totNode; i++) {
        scanf("%d", &fa);
        if(fa == 0) root = i;
        else{
            G[fa].push_back(i); G[i].push_back(fa);
        }
    }

    dfs(root);

    scanf("%d", &totQuery);
    for (int i = 0; i < totQuery; i++) {
        scanf("%d%d", &fr, &to); fr ^= last_ans; to ^= last_ans;
        printf("%d\n", (last_ans=LCA(fr, to)));
    }

    return 0;
}
