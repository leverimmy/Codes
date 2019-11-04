#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 1000050

using namespace std;

int n, k, siz, L, R;
int lg2[maxn] = { -1, 0}, a[maxn], sum[maxn];
int f[maxn][100];
ll ans;

il int read()
{
    rgi x = 0, f = 0, ch;
    while(!isdigit(ch = getchar())) f |= ch == '-';
    while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

il void write(int x)
{
    if(x < 0)	putchar('-'), x = -x;
    if(x > 9)	write(x / 10);
    putchar(x % 10 + 48);
}

int query(int l, int r)
{
    int len = lg2[r - l + 1];
    int x = f[l][len], y = f[r - (1 << len) + 1][len];
    return sum[x] > sum[y] ? x : y;
}

struct node
{
    int s, l, r, pos;
} h[maxn];

int calc(int x)
{
    return sum[h[x].pos] - sum[h[x].s - 1];
}

void push(int _s, int _l, int _r)
{
    h[++siz].s = _s;
    h[siz].l = _l;
    h[siz].r = _r;
    h[siz].pos = query(_l, _r);
    int cur = siz;
    while(cur > 1)
    {
        if(calc(cur) > calc(cur >> 1))
            swap(h[cur], h[cur >> 1]);
        cur >>= 1;
    }
}

void pop()
{
    swap(h[1], h[siz--]);
    int cur = 1;
    while((cur << 1) <= siz)
    {
        int lc = cur << 1, rc = lc + 1, nxt;
        if(rc <= siz)
        {
            if(calc(lc) >= calc(rc))
                nxt = lc;
            else
                nxt = rc;
        }
        else
            nxt = lc;
        if(calc(cur) < calc(nxt))
            swap(h[cur], h[nxt]), cur = nxt;
        else
            break;
    }
}

struct node top()
{
    return h[1];
}

int main()
{
    n = read(), k = read(), L = read(), R = read();
    for(rgi i = 1; i <= n; ++i)
    {
        a[i] = read();
        sum[i] = a[i] + sum[i - 1];
        f[i][0] = i;
        lg2[i] = lg2[i >> 1] + 1;
    }
    for(rgi j = 1; j <= lg2[n]; ++j)
        for(rgi i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            int x = f[i][j - 1];
            int y = f[i + (1 << (j - 1))][j - 1];
            f[i][j] = sum[x] > sum[y] ? x : y;
        }
    for(rgi i = 1; i <= n; ++i)
        if(i + L - 1 <= n)
            push(i, i + L - 1, min(i + R - 1, n));
    while(k--)
    {
        int s = top().s, l = top().l, r = top().r, pos = top().pos;
        pop();
        ans += sum[pos] - sum[s - 1];
        if(l != pos)
            push(s, l, pos - 1);
        if(r != pos)
            push(s, pos + 1, r);
    }
    printf("%lld", ans);
    return 0;
}

