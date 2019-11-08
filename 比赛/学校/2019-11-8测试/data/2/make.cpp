#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("2.in", "w", stdout);
    srand(time(0));
    for (int task = 1; task <= 10; task++)
    {
        int m = 50000;
        for (int i = 1; i <= m - 1; ++i)
            printf("%c", 'A');
        printf("%c", 'B');
        int k = rand() % 2;
        for (int i = 1; i <= m - k; ++i)
            printf("%c", 'A');
        if (k) printf("%c", 'B');
        printf("\n");
        for (int i = 1; i <= m; ++i)
            printf("%c", 'A');
        printf("\n");        
    }
    return 0;   
}
