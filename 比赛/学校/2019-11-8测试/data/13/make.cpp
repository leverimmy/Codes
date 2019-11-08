#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("13.in", "w", stdout);
    for (int j = 1; j <= 10; j++)
    {
        printf("%d", rand() % 9 + 1);
        for (int i = 1; i <= 99999; i++) printf("%d", rand() % 10);
        printf("\n%d\n", rand() % 10000);
    }
    return 0;
}
