#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("5.in", "w", stdout);
    for (int t = 1; t <= 3; t++)
    {
        int n = 10000 - rand() % 10; 
        int m = 100000 - rand() % 10;
        printf("%d %d\n", n, m);
        for (int i = 1; i <= m; i++)
            printf("%d %d %d\n", rand() % n + 1, rand() % n + 1, rand() % 10001);
    }  
    return 0;   
}
