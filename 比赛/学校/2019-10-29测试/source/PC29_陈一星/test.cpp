#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<time.h>
#define LL long long
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
const int M=50200000;
using namespace std;
inline int read(){
	int x=0,f=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
int n,dp[M],pre[M],len;
struct line{
	int l,r,id;
}e[M];
inline bool cmp(line a,line b){
	return a.r<b.r||(a.r==b.r&&a.id<b.id); 
}
int t[M],maxx[M];
inline int lowbit(int x){
	return x&(-x);
}
inline void modify(int a,int x,int pos){
	while (a<=len){
		if (t[a]<x) t[a]=x,maxx[a]=pos;
		if (t[a]==x) maxx[a]=min(maxx[a],pos);
		a+=lowbit(a);
	}
}
int pos;
inline int query(int a){
	int ans=0;pos=0;
	while (a>0){
		if (ans<t[a]) ans=t[a],pos=maxx[a];
		if (ans==t[a]) pos=min(pos,maxx[a]);
		a-=lowbit(a);
	}
	return ans;
}
int maxpos,maxans;
stack<int>c;
int array[M];
signed main(void){
//	freopen("interval4.in","r",stdin);
	n=read();
	for (int i=1;i<=n;i++) e[i].l=read(),e[i].r=read(),len=max(len,e[i].r),e[i].id=i;
	sort(e+1,e+n+1,cmp);
	for (int i=1;i<=n;i++){
		dp[i]=query(e[i].l-1)+1;
		modify(e[i].r,dp[i],i);
		pre[i]=pos;
		if (maxans<dp[i]||(maxans==dp[i]&&e[maxpos].id>e[i].id))
			maxans=dp[i],maxpos=i;
	}
	printf("%d\n",maxans);
	int now=maxpos;
	while (now) array[++array[0]]=e[now].id,now=pre[now];
	sort(array+1,array+array[0]+1);
	for (int i=1;i<=array[0];i++) printf("%d ",array[i]);
	return 0;
}
