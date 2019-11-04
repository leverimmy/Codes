#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 501005
#define ll long long
int n,m,i,r,now,d[N],p[N],q[N],nxt[N];
ll dis,ans,sum[N]; 
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d%d",&d[i],&p[i]),sum[i]=sum[i-1]+1ll*d[i];
    for(i=n;i;i--){
        while(r&&p[q[r]]>p[i])r--;
        nxt[i]=q[r];q[++r]=i;
        if(!nxt[i])nxt[i]=n+1;
    }
    ans=0;now=0;
    for(i=1;i<=n;i++){
        now-=d[i-1];
        if(now<0){puts("-1");return 0;}
        dis=min(sum[nxt[i]-1]-sum[i-1],1ll*m);
        if(dis>now)ans+=1ll*(dis-now)*p[i],now=dis;
    }
    printf("%lld\n",ans);
    return 0;
}