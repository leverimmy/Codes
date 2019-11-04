#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int T, n, tot, flag;
int p[N], num[N];

struct IN
{
    int u, v, flag;
} a[N];

bool cmp(struct IN a, struct IN b)
{
    return a.flag > b.flag;
}

int Init()
{
    for(int i = 1; i <= n << 1; ++i)
        p[i] = i;
}

int Find(int x)
{
    return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union(int a, int b)
{
    int pa = Find(a);
    int pb = Find(b);
    if(pa != pb)
        p[pa] = pb;
}

int main()
{
    cin >> T;
    while(T--)
    {
        tot = 0, flag = 1;
        cin >> n;
        for(int i = 1; i <= n; ++i)
        {
            cin >> a[i].u >> a[i].v >> a[i].flag;
            num[++tot] = a[i].u;
            num[++tot] = a[i].v;
        }
        sort(a + 1, a + n + 1, cmp);
        sort(num + 1, num + tot + 1);
        tot = unique(num + 1, num + tot + 1) - num;
        for(int i = 1; i <= n ; ++i)
        {
            a[i].u = lower_bound(num + 1, num + tot + 1, a[i].u) - num;
            a[i].v = lower_bound(num + 1, num + tot + 1, a[i].v) - num;
        }
        Init();
        for(int i = 1; i <= n; ++i)
        {
            if(a[i].flag)
                Union(a[i].u, a[i].v);
            else
            {
                if(Find(a[i].u) == Find(a[i].v))
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}

