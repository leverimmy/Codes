#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N << 1], b[N << 1], c[N << 1];

void Add(int x, int val)
{
    for(; x <= (N << 1) - 1; x += x & -x)
        c[x] += val;
}

int Query(int x)
{
    int res = 0;
    for(; x; x -= x & -x)
        res += c[x];
    return res;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    for(int i = 1; i <= n; ++i)
        Add(i, b[i]);
    for(int i = 1; i <= m; ++i)
    {
        string str;
        cin >> str;
        if(str[0] == 'Q')
        {
            int x;
            cin >> x;
            cout << Query(x) << endl;
        }
        else if(str[0] == 'C')
        {
            int l, r, w;
            cin >> l >> r >> w;
            Add(l, w);
            Add(r + 1, -w);
        }
    }
    return 0;
}
