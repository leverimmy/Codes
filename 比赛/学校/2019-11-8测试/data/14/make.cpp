#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("14.in", "w", stdout);
    for (int j = 1; j <= 10; j++)
    {
        for (int k = 1; k <= 2; ++k)
        {
            printf("%d", rand() % 9 + 1);
            for (int i = 1; i <= 999; i++) printf("%d", rand() % 10);
            printf("\n");
        }
    }
    return 0;
}
