#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define int64 long long
#define RG register
using namespace std;

char ch[5050][5050];
int n,m,a[5050][5050],sum[5050][5050],ans;

int lowbit(int x)   {   return x & -x;   }
void push(int whe,int node)
{
    while (node <= whe)
        {
            sum[whe][node]++;  node += lowbit(node);
        }
}
void find(int whe,int node)
{
    int tot = 0,z = node;
    while (node)
        {
            tot += sum[whe][node];  node -= lowbit(node);
        }
    ans = max(ans,tot * (whe - z + 1));
}
inline void work()
{
    for (RG int i = 1;i <= n;i++)
        {
            RG int l = 1;
            for (RG int j = 1;j <= m;j++)
                {
                    if (!a[i][j])    {l = j + 1;continue;}
                    push(j,l);
                }
        }
    for (RG int i = 1;i <= m;i++)
        for (RG int j = 1;j <= i;j++)
            {
                find(i,j);
            }
    cout << ans;
}

int main()
{
	freopen("matrix.in","r",stdin);     freopen("matrix.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)  scanf("%s",ch[i] + 1);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            a[i][j] = ch[i][j] - '0';
    work();
}
  
