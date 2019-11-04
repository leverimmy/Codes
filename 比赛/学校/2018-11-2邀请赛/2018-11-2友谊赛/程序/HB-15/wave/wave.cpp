#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
const int maxn=150010;
int n;
ll ans=0;
struct line//线段
{
    bool v;//是否是竖着的，1=竖着，0=横着
    int x1,y1,x2,y2;//起始坐标(x,y)，终点坐标(x2,y2)
}a[maxn];
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
void add(int cnt,int x,int y)
{
    int t=cnt<<1;
    for(int i=1;i<=t-2;i++)//更新在此范围内的线段
    {
        if(!a[i].v&&a[i].x1<=x&&a[i].y1<=y)//横着的线段起点在里面时
            a[i].x1=x;
        else if(a[i].v&&a[i].x1<=x&&a[i].y2<=y)//竖着的终点在里面时
            a[i].y2=y;
    }
    a[t-1].v=0;
    a[t-1].x1=0;
    a[t-1].y1=a[t].y2=y;
    a[t-1].x2=x;
    a[t].v=1;
    a[t].x1=a[t].x2=x;
    a[t].y1=y;
    a[t].y2=0;
}
void get()
{
    for(int i=1;i<=n<<1;i++)
    {
        if(!a[i].v)ans+=a[i].x2-a[i].x1;
        else ans+=a[i].y1-a[i].y2;
    }
}
void debug()
{
    for(int i=1;i<=n<<1;i++)
    {
        if(!a[i].v)cout<<"横线"<<i<<"："<<a[i].x1<<"~"<<a[i].x2<<" 长度："<<a[i].x2-a[i].x1<<endl;
        else cout<<"竖线"<<i<<"："<<a[i].y1<<"~"<<a[i].y2<<" 长度："<<a[i].y1-a[i].y2<<endl;
    }
}
int main()
{
    freopen("wave.in","r",stdin);
    freopen("wave.out","w",stdout);
    int x,y;
    n=read();
    for(int i=1;i<=(n<<1);i++)
        a[i].v=a[i].x1=a[i].x2=a[i].y1=a[i].y2=0;
    for(int i=1;i<=n;i++)
    {
        x=read(),y=read();
        add(i,x,y);
    }
    //debug();
    get();
    cout<<ans<<endl;
}
