#include<bits/stdc++.h>
using namespace std;
const int N=305;
int n,m,res[N],ans[N][N],a[N*N],cnt;
bool use[N*N];
int read() 
{
    char c=getchar(); int f=1,x=0;
    while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
    while (isdigit(c)) {x=x*10+c-'0'; c=getchar();}
    return f*x;
}
void check(int x) 
{
    memset(use,false,sizeof(use));
    if((a[1]+a[2]+a[x])&1)return;
    res[1]=(a[1]+a[2]+a[x])/2-a[x];
    res[2]=a[1]-res[1];
    res[3]=a[2]-res[1];
    use[1]=use[2]=use[x]=true; 
    for(int i=4,j=3;i<= n; ++i) 
	{
        while(j<=m&&use[j]) j++;
        if(j>m) return;
        res[i]=a[j]-res[1];
        use[j]=true;
        for(int k=2;k<i;++k) 
		{
            if(res[k]>res[i]) return;
            int v=res[k]+res[i];
            int p=lower_bound(a+1,a+m+1,v)-a;
            if(a[p]!=v) return;
            int px=p;
            while(px&&a[px]==a[p]) px--;
			px++;
            while(px<=m&&a[px]==a[p]&&use[px]) px++;
            if(a[px]!=a[p]||use[px]) return;
            p=px;
            use[p]=true;
        }
    }
    cnt++;
    for(int i=1;i<=n;++i) ans[cnt][i] = res[i];
}
int main() 
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	n=read();
    m=n*(n-1)/2;
    for(int i=1;i<=m;++i) a[i]=read();
    sort(a+1,a+m+1);
    for(int i=3;i<=m;) 
	{ 
        check(i);
        int j=i;
        while(j<=m&&a[j]==a[i]) j++;
        i=j;
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;++i)
        for(int j=1;j<=n;++j)
		{
            printf("%d",ans[i][j]);
            if(j==n) printf("\n");
            else printf(" ");
        }
    return 0;
} 
