#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#define M 50100
#define LL long long
const int inf=0x3f3f3f3f;
const double eps=1e-9;
using namespace std;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){if (s=='-') f=-1; s=getchar();}
	while (isdigit(s)){x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	return x*f;
}
int n,l,ans,now,pre,cnt=1,mid[M],num[M];
struct fw{
	int t,p;
}a[M];
inline bool cmp(fw a,fw b){
	return a.t<b.t||(a.t==b.t&&a.p<b.p);
}
inline int get_dis(int c,int d){
	int h=(c+d)/2,ans=0;
	ans=(h-c+1)*a[h].p-(s[h]-s[c-1]);
	ans+=(s[d]-s[h])-a[h].p*(d-h);
	return ans;
}
stack<int>c;
signed main(void)
{
//	freopen("firework.in","r",stdin);
//	freopen("firework.out","w",stdout);
	n=read(),l=read();
	for (int i=1;i<=n;i++) a[i].t=read(),a[i].p=read();
	sort(a+1,a+n+1,cmp);a[0].t=a[1].t;
	pre=1;
	for (int i=1;i<=n;i++){
		if (a[i].t!=a[i-1].t)
			mid[cnt]=(pre+i)/2,pre=i,cnt++;
		a[i].t=cnt;
		num[cnt]++;
	}
	printf("%d",ans);
	return 0;
}


