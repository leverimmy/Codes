#include <queue>
#include <cstdio>
using namespace std;

int m;
priority_queue<int> a;

int main()
{
    freopen("9.in", "r", stdin);
    freopen("9.out", "w", stdout);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        int j; scanf("%d", &j);
        if (j == 1)
        {
            int k; scanf("%d", &k);
            a.push(k);
        }
        else 
            if (a.empty()) printf("-1");
            else {
                printf("%d\n", a.top());
                a.pop();
            }
    }
    return 0;
}
