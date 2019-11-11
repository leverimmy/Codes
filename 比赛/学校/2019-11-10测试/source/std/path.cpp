#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200005
using namespace std;
int n;
int totaledge,point[MAXN],v[MAXN],w[MAXN],next[MAXN];
int f[MAXN][2];
int g[MAXN][2];
int ans[MAXN];
void addedge(int x,int y,int z){
    totaledge++;
    v[totaledge] = y;
    w[totaledge] = z;
    next[totaledge] = point[x];
    point[x] = totaledge;
}
void dfs1(int fa, int x){
    int i,j;
    for (i=point[x];i;i=next[i]){
        if (v[i] == fa) continue;
        dfs1(x, v[i]);
        j = f[v[i]][0] + w[i];
        if (j>f[x][0]){
            f[x][1] = f[x][0];
            g[x][1] = g[x][1];
            f[x][0] = j;
            g[x][0] = v[i];
        }
        else if (j>f[x][1]){
            f[x][1] = j;
            g[x][1] = v[i];
        }
    }
}
void dfs2(int fa, int x,int y){
    int i,j;
    ans[x] = max(f[x][0],y);
    for (i=point[x];i;i=next[i]){
        if (v[i] == fa) continue;
        if (g[x][0]!=v[i]) dfs2(x, v[i],max(y,f[x][0])+w[i]);
            else dfs2(x, v[i],max(y,f[x][1])+w[i]);
    }
}
int d[MAXN];
char str[20];
int main(){
    int i,x,y,z, t, ri;
//    for (ri = 0; ri < 30; ri++){
//        sprintf(str, "%d.in", ri);
       freopen("path.in", "r", stdin);
//        sprintf(str, "%d.out", ri);
       freopen("path.out", "w", stdout);
        scanf("%d",&n);
        memset(point,0,sizeof(point));
        totaledge = t = 0;
        for (i=2;i<=n;i++){
            scanf("%d%d%d",&x,&y, &z);
            addedge(x,y,z);
            addedge(y,x,z);
            t += z + z;
        }
        z = 0;
        for (i = 1; i <= n; i++){
            scanf("%d", &d[i]);
            z += d[i];
        }
        if (z == 0){
            printf("-1\n");
            return 0;
        }
        dfs1(0, 1);
        dfs2(0, 1, 0);
        z = 0;
        for (i=1;i<=n;i++){
            if (d[i]) z = max(z, ans[i]);
        }
        printf("%d\n", t - z);
//    }
    return 0;
}
