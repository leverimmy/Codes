#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("16.in", "w", stdout);
    for (int t = 1; t <= 10; t++)
    {
        int n = 1000 - rand() % 10; 
        int m = 2000 - rand() % 10;
        int t = 1000; 
        printf("%d %d\n", n, m);
        for (int i = 1; i <= m; i++)
            printf("%d %d %d\n", rand() % n + 1, rand() % n + 1, rand() % (t + 10001) - t);
    }  
    return 0;   
}
