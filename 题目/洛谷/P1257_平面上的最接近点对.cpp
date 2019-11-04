#include <cstdio>
#include <cmath>
#include <algorithm>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int n;
const int maxn = 200000 + 10;
const int inf = 0x3f3f3f3f;
int temp[maxn];

struct point
{
    double x;
    double y;
} p[maxn];

bool cmp1(struct point A, struct point B)
{
    if(A.x == B.x)
        return A.y < B.y;
    else
        return A.x < B.x;
}

bool cmp2(int a, int b)
{
    return p[a].y < p[b].y;
}

double dist(int a, int b)
{
    return sqrt((p[a].x - p[b].x) * (p[a].x - p[b].x) + (p[a].y - p[b].y) * (p[a].y - p[b].y));
}

double merge(int l, int r)
{
    double d = inf;
    if(l == r)
        return d;
    if(l + 1 == r)
        return dist(l, r);
    int mid = (l + r) >> 1;
    double d1 = merge(l, mid);
    double d2 = merge(mid + 1, r);
    d = min(d1, d2);
    int cnt = 0;
    for(int i = l; i <= r; i++)
        if(fabs(p[mid].x - p[i].x) <= d)
            temp[cnt++] = i;
    sort(temp, temp + cnt, cmp2);
    for(int i = 0; i < cnt; i++)
        for(int j = i + 1; j < cnt && p[temp[j]].y - p[temp[i]].y < d; j++)
        {
            double d3 = dist(temp[i], temp[j]);
            d = min(d, d3);
        }
    return d;
}

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d", &n);
    for(rgi i = 0; i < n; ++i)
        scanf("%lf %lf", &p[i].x, &p[i].y);
    sort(p, p + n, cmp1);
    printf("%.4f", merge(0, n - 1));
    return 0;
}
