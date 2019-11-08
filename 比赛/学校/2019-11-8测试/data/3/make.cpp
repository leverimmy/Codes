#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("3.in", "w", stdout);
    for (int t = 1; t <= 40; t++)
    {
        int n = rand() % 10000 + 1; 
        int m = ((rand() << 15) + rand()) % 100000 + 1;
        printf("%d %d\n", n, m);
        for (int i = 1; i <= m; i++)
            printf("%d %d\n", rand() % n + 1, rand() % n + 1);
    }  
    return 0;   
}
