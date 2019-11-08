#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("4.in", "w", stdout);
    int n = 1000000;
    printf("%d\n", n);
    for (int i = 1; i <= n; ++i)
        printf("%d ", rand());
    return 0;   
}
