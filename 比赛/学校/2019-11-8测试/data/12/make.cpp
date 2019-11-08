#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("12.in", "w", stdout);
    printf("10\n10\n");
    printf("2340982435874396876937846923439408546734986734\n2340982435874396876937846923439408546734986733\n");
    for (int j = 1; j <= 10; j++)
    {
        int n = 100000 - rand();
        printf("%d", rand() % 9 + 1);
        for (int i = 1; i <= n - 1; i++) printf("%d", rand() % 10); printf("\n");
        n -= rand() % 2 + 1;
        printf("%d", rand() % 9 + 1);
        for (int i = 1; i <= n - 1; i++) printf("%d", rand() % 10); printf("\n");
    }
    return 0;
}
