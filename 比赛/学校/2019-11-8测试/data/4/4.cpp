#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[1000010];

int main()
{
    freopen("4.in", "r", stdin);
    freopen("4.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]);   
    return 0;   
}
