#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <assert.h>
#define mod 1000000007
using namespace std;
int i,j,k,n,m,s,t,ans;
long long a,b,c;
long long A,B,C;
long long f[105][105][105];
long long x1[10000];
long long y1[10000];
long long z1[10000];
long long x2[10000];
long long y2[10000];
long long z2[10000];
int k1,k2,l1,l2,K;
long long mini;
long long oo = (long long)1000000000*1000000000;
void init()
{
    x1[0] = a;y1[0] = b;z1[0] = c;
    k1 = 0;
    while (k1<=K)
    {
        if (y1[k1]-x1[k1]==z1[k1]-y1[k1]) break;
        if (y1[k1]-x1[k1]<z1[k1]-y1[k1])
        {
            k1++;
            x1[k1] = y1[k1-1];
            y1[k1] = 2*y1[k1-1]-x1[k1-1];
            z1[k1] = z1[k1-1];
        } else
        {
            k1++;
            x1[k1] = x1[k1-1];
            y1[k1] = 2*y1[k1-1]-z1[k1-1];
            z1[k1] = y1[k1-1];
        }
    }
    x2[0] = A;y2[0] = B;z2[0] = C;
    k2 = 0;
    while (k2<=K)
    {
        if (y2[k2]-x2[k2]==z2[k2]-y2[k2]) break;
        if (y2[k2]-x2[k2]<z2[k2]-y2[k2])
        {
            k2++;
            x2[k2] = y2[k2-1];
            y2[k2] = 2*y2[k2-1]-x2[k2-1];
            z2[k2] = z2[k2-1];
        } else
        {
            k2++;
            x2[k2] = x2[k2-1];
            y2[k2] = 2*y2[k2-1]-z2[k2-1];
            z2[k2] = y2[k2-1];
        }
    }
  //  for (int i=0; i<=k1; i++) cout<<x1[i]<<' '<<y1[i]<<' '<<z1[i]<<endl;
    mini = oo;
    for (int i=0;i<=k1;i++)
    for (int j=0;j<=k2;j++)
    if (x1[i]==x2[j]&&y1[i]==y2[j]&&z1[i]==z2[j])
    if (i+j<mini)
    {
        l1 = i;
        l2 = j;
        mini = i+j;
    }
}
long long dfs(int i,int j,int k)
{
    if (f[i][j][k]!=-1) return f[i][j][k];
    f[i][j][k] = 0;
    if (i==j&&j==k&&k==0)
    {
        f[i][j][k] = 1;
        return 1;
    }
    if (i+j>k) return 0;
    if (i==0&&j>k2) return 0;
    if (i==0&&j==0&&k>0)
    {
        long long t1 = dfs(0,1,k-1);
        long long t2 = dfs(1,0,k-1);
        f[i][j][k] = (t1+t2*2)%mod;
    } else if (i==0&&j>0)
    {
        long long t1 = dfs(0,j+1,k-1);
        long long t2 = dfs(1,j,k-1);
        long long t3 = dfs(0,j-1,k-1);
        f[i][j][k] = (t1+t2+t3)%mod;
    } else if (i>0)
    {
        long long t1 = dfs(i-1,j,k-1);
        long long t2 = dfs(i+1,j,k-1);
        f[i][j][k] = (t1+t2*2)%mod;
    }
    return f[i][j][k];
}
int main()
{
    freopen("rabbits.in","r",stdin);
	freopen("rabbits.out","w",stdout);
    int T;
    long long INF=1ll*1000000000*1000000000;
    //scanf("%d",&T);
	T=1;
    while (T--)
    {
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        //if (a>b) swap(a,b); if (a>c) swap(a,c); if (b>c) swap(b,c);
        scanf("%I64d%I64d%I64d",&A,&B,&C);
       // if (A>B) swap(A,B); if (A>C) swap(A,C); if (B>C) swap(B,C);
        assert(-INF<=a && -INF<=A && -INF<=b && -INF<=B && -INF<=c && -INF<=C);
        assert(a<=INF && A<=INF && b<=INF && B<=INF && c<=INF && C<=INF);
        assert(a<b && b<c); assert(A<B && B<C);
        scanf("%d",&K);
        init();
        if (l1+l2>K||mini==oo)
        {
            printf("0\n");
            continue;
        }
        memset(f,-1,sizeof(f));
        f[0][0][0] = 1;
        printf("%I64d\n",dfs(l1,l2,K));
    }
    return 0;
}

