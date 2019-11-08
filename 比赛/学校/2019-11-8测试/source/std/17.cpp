#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
#define FOR(i,a,b) for(register int i(a);i<=b;++i)
#define For(i,a,b) for(register int i(a);i>=b;--i)
ifstream fin;
ofstream fout;
typedef long long ll;
const int MX=20010;
const int MX1=500010;
const int inf=99999999;
struct star{int r,c;}s[MX];
int ran[MX];
int ans[MX],c[MX];
int n,t=654684894,tt;
bool cmp1(int x,int y){return s[x].r<s[y].r;}
bool cmp2(int x,int y){return s[x].c<s[y].c;}
bool cmp3(star x,star y){return x.r==y.r?x.c<y.c:x.r<y.r;}
int lb(int x){return x&(-x);}
void add(int x){for(;x<=n;x+=lb(x)) c[x]++;}
int sum(int x)
{
    int ret=0;
    for(;x;x-=lb(x)) ret+=c[x];
    return ret;
}
void work()
{
    FOR(i,1,n) fin>>s[i].c>>s[i].r;
    FOR(i,1,n) ran[i]=i;
    sort(ran+1,ran+n+1,cmp1);
    FOR(i,1,n)
    {
        tt=s[ran[i]].r;
        if(tt==t) s[ran[i]].r=s[ran[i-1]].r;
        else s[ran[i]].r=i;
        t=tt;
    }
    FOR(i,1,n) ran[i]=i;
    sort(ran+1,ran+n+1,cmp2);
    t=654684894;
    FOR(i,1,n)
    {
        tt=s[ran[i]].c;
        if(tt==t) s[ran[i]].c=s[ran[i-1]].c;
        else s[ran[i]].c=i;
        t=tt;
    }
    sort(s+1,s+n+1,cmp3);
    int u,v;
    FOR(i,1,n)
    {
        u=s[i].c;
        v=sum(u);
        add(u);
        ++ans[v];
    }
    FOR(i,0,n-1) fout<<ans[i]<<endl;
}
int main()
{
    fin.open("17.in");
    fout.open("17.out");
    while(fin>>n)
    {
        work();
        n=0;t=654684894;tt=0;
        memset(ans,0,sizeof(ans));
        memset(c,0,sizeof(c));
    }
    fin.close();
    fout.close();
    return 0;
}
