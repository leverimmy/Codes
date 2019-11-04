#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<queue>
#include<map> 
#define M 600100
#define inf 0x3f3f3f3f 
#define LL long long
using namespace std;
LL n,m;
map<string,LL>mapp;
inline LL read()
{
	LL f=1,x=0;char s=getchar();
	while (!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while (isdigit(s))
	{
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*f;
}
signed main(void)
{
	freopen("liverpool.in","r",stdin);
	freopen("liverpool.out","w",stdout);
	n=read();
	for (LL i=1;i<=n;i++){
		string s;cin>>s;
		LL x=read();
		mapp[s]=x;
	}
	m=read();
	for (LL i=1;i<=m;i++){
		LL x=read(),ans=0;
		for (int j=1;j<=x;j++){
			string s;cin>>s;
			if (ans==-1) continue;
			if (!mapp.count(s)) {
				 ans=-1;
				 continue;
			}
			ans+=mapp[s];
		}
		printf("%lld\n",ans);
	}
    return 0;
}

