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

int n;

int main()
{
    freopen("17.in", "w", stdout);
    n = 15000;
    printf("%d\n", n);
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", (rand() << 15) + rand(), (rand() << 15) + rand());
    return 0;
}
