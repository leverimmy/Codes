#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
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
#define N 1000005

int n, m, z[N], q[N];

int main()
{
    freopen("7.in", "r", stdin);
    freopen("7.out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 2, n)
    {
        if (!z[i]) 
        {
            q[++m] = i; z[i] = m; printf("%d ", i);
        }
        FOR (j, 1, m)
        {
            if (q[j] * i > n) break;
            z[q[j] * i] = j;
        }
    }
    return 0;
}
