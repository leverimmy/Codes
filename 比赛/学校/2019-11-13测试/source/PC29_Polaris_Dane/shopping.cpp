#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cctype>
#include<set>
#define LL long long
#define M 600010
#define N 50010
#define int long long 
using namespace std;
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
priority_queue<int,vector<int>,greater<int> >que,del;
vector<int>in[M],dele[M];
int dp[M];
int a[M],n,m,s[M];
signed main(void){
//	freopen("shopping.in","r",stdin);
//	freopen("shopping.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read(),s[i]=s[i-1]+a[i];
	for (int i=1;i<=m;i++){
		int u=read(),v=read();
		if (u>v) swap(u,v);
		in[u].push_back(u),dele[v+1].push_back(u);
	}
	for (int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for (int j=0;j<in[i].size();j++) que.push(in[i][j]);
		for (int j=0;j<dele[i].size();j++) del.push(dele[i][j]);
		while (!que.empty()&&!del.empty()&&que.top()==del.top()) que.pop(),del.pop();
		for (int j=que.empty()?inf:que.top();j<=i;j++)
			dp[i]=max(dp[i],dp[j-1]+(s[i]-s[j-1])*(s[i]-s[j-1]));
	}
	printf("%lld",dp[n]);
}

