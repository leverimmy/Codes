//#include <bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
const int N=2115;
const int INF=1e7;
typedef long long LL;
using namespace std;
vector <int> ap[N];
int n,n1,st,ed,f[N][N];
LL ans,pr[N][N];
void link(int x,int y,int w,LL c)
{
    ap[x].push_back(y);
    f[x][y]=w,pr[x][y]=c;
    ap[y].push_back(x);
    f[y][x]=0,pr[y][x]=-c;
}
typedef vector<int>::iterator IT;
namespace Flow
{
    LL dis[N];
    bool bz[N];
    IT cur[N];
    int d[200*N];
    bool spfa()
    {
        memset(dis,107,sizeof(dis));
        memset(bz,0,sizeof(bz));
        dis[st]=0,bz[st]=1,d[1]=st;
        fo(i,1,n1) cur[i]=ap[i].begin();
        int l=0,r=1;
        while(l<r)
        {
            int k=d[++l];
            for(IT i=ap[k].begin();i!=ap[k].end();i++)  
            {
                int p=*i;
                if(f[k][p]&&dis[k]+pr[k][p]<dis[p]) 
                {
                    dis[p]=dis[k]+pr[k][p];
                    if(!bz[p]) bz[p]=1,d[++r]=p;
                }
            }
            bz[k]=0;
        }
        return (dis[ed]<=1e17);
    }
    int flow(int k,int s)
    {
        if(k==ed) return s;
        int sl=0,v;
        bz[k]=1;
        for(;cur[k]!=ap[k].end();cur[k]++)
        {
            int p=*cur[k];
            if(!bz[p]&&f[k][p]&&dis[p]==dis[k]+pr[k][p]) 
            {
                if(v=flow(p,min(s,f[k][p]))) 
                {
                    sl+=v,s-=v;
                    f[k][p]-=v,f[p][k]+=v;
                    ans+=(LL)v*pr[k][p];
                    if(!s) break;
                }
            }
        }
        bz[k]=0;
        return sl;
    }
}
using Flow::flow;
using Flow::spfa;
int main()
{   freopen("offsheet.in","r",stdin);
  freopen("offsheet.out","w",stdout);
    cin>>n;
    n1=2*n+6,st=2*n+5,ed=n1;
    fo(i,1,n) 
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        link(st,i,z,0);
        link(i,2*n+1,z,x+y);
        link(i,2*n+2,z,x-y);
        link(i,2*n+3,z,-x+y);
        link(i,2*n+4,z,-x-y);
    }  
    fo(i,1,n) 
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        link(i+n,ed,z,0);
        link(2*n+1,i+n,z,-x-y);
        link(2*n+2,i+n,z,-x+y);
        link(2*n+3,i+n,z,x-y);
        link(2*n+4,i+n,z,x+y);
    }
    ans=0;
    while(spfa()) 
        flow(st,INF);
    printf("%lld\n",-ans);
}
