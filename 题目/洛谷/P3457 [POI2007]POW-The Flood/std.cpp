#include<bits/stdc++.h>

using namespace std;
const int N = 1010;
int n, m, ans;
int a[N][N];
struct node
{
    int x, y, h;
    bool operator <(const node &z)const
    {
        return h<z.h;
    }
}p[N*N];
int pl;
//int fa[N*N], num[N][N], s[N*N];
int fa[N*N], s[N*N];
int find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void hb(int x, int y)
{
    int X = find(x), Y = find(y);
    s[Y] |= s[X];
    fa[X] = Y;
    /*??????,???fa[Y] = X? 
    ???fa[Y] = X, ???????s[X] |= s[Y]?
    ??, Y???????, X??????
    ?
        s[Y] |= s[X];
        fa[Y] = X;
    ????? s[Y] = 1, s[X] = 0?
    ???
    ?find(Y) = X
    s[X] = 0, ???????????
    ??,???????????
    */
    return ;
}

int Get(int a, int b) {
	return (a - 1) * m + b;
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(a, 127, sizeof(a));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
//            num[i][j] = ++pl;
            p[++pl] = (node){i, j, abs(a[i][j])};
        }
    sort(p+1, p+1+pl);
    for(int i = 1; i <= pl; i++)
        fa[i] = i;
    for(int i = 1; i <= pl; i++)
    {
        int X = p[i].x, Y = p[i].y;
        for(int j = 0; j < 4; j++)
        {
            int x = X + mov[j][0], y = Y + mov[j][1];
            if(abs(a[x][y]) <= p[i].h)
                hb(Get(x, y), Get(X, Y));
        }
        if(p[i].h != p[i+1].h)
            for(int j = i; p[j].h == p[i].h; j--)
                if(a[p[j].x][p[j].y]>0)
                {
                    int x = find(Get(p[j].x, p[j].y));
                    if(!s[x])
                        s[x] = 1, ans++;
                }
    }
    printf("%d\n", ans);
    return 0;
}
