#include <cstdio>
using namespace std;

int a, b, c;

int cal(int b)
{
    if (b == 0) return 1;
    else 
    {
        int k = cal(b >> 1);
        k = k * k % c;
        if (b & 1) k = k * a % c;
        return k;
    }
}       

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    while (scanf("%d%d%d", &a, &b, &c) != EOF)
        printf("%d\n", cal(b));
    return 0;
}
