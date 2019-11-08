#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    freopen("9.in", "w", stdout);
    srand(time(0));
    int task = 100000;
    printf("%d\n", task);
    for (int i = 1; i <= task / 10; ++i) printf("1 %d\n", rand());
    for (int i = 1; i <= task * 9 / 10; ++i)
    if (rand() & 1)
        printf("1 %d\n", rand());
    else printf("2\n");
    return 0;
}
