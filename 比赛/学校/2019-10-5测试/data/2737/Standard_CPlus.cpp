#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 5e5+100;

int n,m;
int dis[maxn],res[maxn],ans[maxn];

struct index
{
    int val,idx;
}T[maxn];
bool operator < (index x,index y)
{
    return x.val < y.val || x.val ==y.val && x.idx < y.idx;
}

struct query
{
    int l,r,idx;
}F[maxn];
bool operator <(query x,query y)
{
    return x.r < y.r;
}

int low(int x)
{
    return x&(-x);
}

void reduce(int idx,int val)
{

    for(;idx; idx-=low(idx))
        res[idx] = min(res[idx],val);
}

int get(int idx)
{
    int val = 1e9+100;
    for(;idx<=n;idx+=low(idx))
        val = min(val,res[idx]);//,cout<<idx<<endl;
    return val;
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&T[i].val),T[i].idx = i;
    sort(T+1,T+1+n);
    for(int i=2;i<=n;i++)
    {
        if(T[i-1].val==T[i].val)
            dis[T[i].idx] = T[i].idx -T[i-1].idx;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&F[i].l,&F[i].r);
        F[i].idx = i;
    }
    sort(F+1,F+1+m);
    F[m+1].r = n;F[m+1].l=1;
    memset(res,0x3f,sizeof(res));
    for(int i=1,j=1;i<=n;i++)
    {
        if(dis[i])
            reduce(i-dis[i],dis[i]);
        for(;F[j].r<=i&&j<=m;j++)
            ans[F[j].idx] = get(F[j].l);
    }
    for(int i=1;i<=m;i++)
    {
        if(ans[i] < 1e9) printf("%d\n", ans[i]);
        else puts("-1");
    }
    return 0;
}