/*
首先环中至少有1个0，所以就是一条链
然后注意到一个结论：选定一个方向沿着边走下去，必须一次性把边上的数取光。
因为如果不取光，显然对方可以倒着走把这条边取光，这样就回到原地，而且不能再往那个方向走。
所以一次走必须把边上的数取光。那么只能一直不回头的走下去了。
如果有奇数条边则先手必胜，如果有偶数条边后手必胜。
这样只要从起始位置往两边搜一下就好了
*/
#include<cstdio>
int a[100];
int n;
int sa,sb;
int main()
{
    freopen("cycle.in","r",stdin);
    freopen("cycle.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    for (int i=n+1;i<=2*n;i++)a[i]=a[i-n];
    for (int i=n;i>=1;i--) if(a[i])sa++;else break;
    for (int i=n+1;i<=2*n;i++)if (a[i])sb++;else break;
    if (sa&1||sb&1)printf("YES");
    else printf("NO");
}