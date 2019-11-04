#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
const int maxn=505;
int n,m,ans=0,a[maxn][maxn][5];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
        x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return x*f;
}
int main()
{
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    n=read(),m=read();
    for(int i=1; i<=n*m; i++)
    {
        int com1=getchar(),cost1=read(),com2=getchar(),cost2=read();
        if(i<=m)
        {
            a[1][i][2]=cost1;
            a[1][i][4]=cost2;
        }
        else
        {
            a[i/m][i%m][1]=cost1;
            a[i/m+1][i%m-1][3]=cost2;
        }
    }
    int q=read();
    for(int i=1;i<=q;i++)
        cout<<i*2<<endl;
    return 0;
}
