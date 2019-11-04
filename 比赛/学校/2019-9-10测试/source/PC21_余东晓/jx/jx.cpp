#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<stack>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
ll a[1000010];
int main()
{
	freopen("jx.in","r",stdin);freopen("jx.out","w",stdout);int n;scanf("%d",&n);int lst(0);for(int i=1;i<=n;i++){ll x;scanf("%lld",&x);if(i==1||x==0||x*lst<0)a[++a[0]]=x;else a[a[0]]+=x;lst=a[a[0]];}
	n=a[0];int tot(0);for(int i=1;i<=n;i++)if(a[i]>0)tot++;for(int i=1;i<=n;i++){if(tot==3)break;if(a[i]<0)continue;int p(0);while(i+p+2<=n&&a[i+p+2]+a[i+p+1]>0){if(tot==3)break;a[i]+=a[i+p+2]+a[i+p+1];a[i+p+1]=a[i+p+2]=-INF;p+=2;tot-=1;}i+=p;}
	std::priority_queue<int>q;for(int i=1;i<=n;i++)q.push(a[i]);ll ans(0);for(int i=1;i<=3;i++){ans+=q.top();q.pop();}return printf("%lld\n",ans),0;
}
