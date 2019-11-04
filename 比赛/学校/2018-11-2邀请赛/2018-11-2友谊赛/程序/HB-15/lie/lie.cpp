#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
const int maxn=100010;
int n,cnt=0,ans=0;
bool a[maxn];
struct line
{
    int a,b;
} p[maxn];
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
bool cmp(line x,line y)
{
    return x.a<y.a;
}
void get()
{
    for(int i=1; i<=cnt; i++)
    {
        int flag=1;
        for(int j=p[i].a; j<=p[i].b; j++)
            if(!a[j])
            {
                a[j]=1;
                flag=0;
                break;
            }
        if(flag)ans++;
    }
}
void debug()
{
    for(int i=1;i<=cnt;i++)
        cout<<"Çø¼ä"<<i<<"£º"<<p[i].a<<" "<<p[i].b<<endl;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}
int main()
{
    freopen("lie.in","r",stdin);
    freopen("lie.out","w",stdout);
    n=read();
    for(int i=1; i<=n; i++)
        a[i]=p[i].a=p[i].b=0;
    int x,y;
    for(int i=1; i<=n; i++)
    {
        x=read(),y=read();
        if(x+y>=n)
        {
            ans++;
            continue;
        }
        else
        {
            p[++cnt].a=x+1;
            p[cnt].b=n-y;
        }
    }
    sort(p+1,p+cnt+1,cmp);
    get();
    //debug();
    cout<<ans<<endl;
}
