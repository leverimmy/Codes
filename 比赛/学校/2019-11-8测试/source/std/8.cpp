#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <memory> 
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#define ED end()
#define FF first
#define SS second
#define BG begin()
#define PB push_back
#define MP make_pair
#define SZ(x) ((int)((x).size()))
#define ran(n) (((rand() << 15) + rand()) % (n) + 1)
#define FOR(i, l, r) for (int i = (l); i <= (r); i++)
#define ROF(i, r, l) for (int i = (r); i >= (l); i--)
#define foreach(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
using namespace std;
#define N 10005
#define M 100005

int n, m, ans, edge[N], z[N], link[N], point[M], next[M]; 

bool find(int i)
{
    for (int b = edge[i]; b; b = next[b])
    {
        int p = point[b];
        if (!z[p])
        {
            z[p] = 1;
            if (!link[p] || find(link[p]))
            {
                link[p] = i; return true;
            }
        }
    }
    return false;
}

int main()
{
    freopen("8.in", "r", stdin);
    freopen("8.out", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        ans = 0;
        memset(edge, 0, sizeof(edge)); memset(link, 0, sizeof(link));
        FOR (i, 1, m) 
        {
            int s; scanf("%d%d", &s, &point[i]);
            next[i] = edge[s]; edge[s] = i;
        }
        FOR (i, 1, n)
        {
            memset(z, 0, sizeof(z)); ans += find(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
