#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("1.in", "w", stdout);
    for (int k = 1; k <= 10000; k++)
        printf("%d %d %d\n", rand() % 10000 + 1, (rand() << 15) + rand(), rand() % 10000 + 1);
    return 0;   
}
