#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#include<cctype>
#include<stack>
#include<queue>
#define int long long
using namespace std;
const int M=200200;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int n,x[M],y[M];
struct node{
	int x,y;
	bool operator <(const node&a)const{
		return x<a.x||(x==a.x&&y<a.y);
	}
}p[M];
int t[M];
inline int lowbit(int x){
	return x&-x;	
}
inline void modify(int a,int x){
	while (a<=n) t[a]+=x,a+=lowbit(a);	
}
inline int sumup(int a){
	int ans=0;
	while (a>0) ans+=t[a],a-=lowbit(a);
	return ans;	
}
int ans[M];
signed main(void){
	freopen("17.in","r",stdin);
	freopen("17.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++){
		x[i]=p[i].x=read();
		y[i]=p[i].y=read();	
	}
	sort(p+1,p+n+1),sort(x+1,x+n+1),sort(y+1,y+n+1);
	for (int i=1;i<=n;i++){
		p[i].x=lower_bound(x+1,x+n+1,p[i].x)-x;
		p[i].y=lower_bound(y+1,y+n+1,p[i].y)-y;
	}
	for (int i=1;i<=n;i++){
		ans[sumup(p[i].y)]++;
		modify(p[i].y,1);
	}
	for (int i=0;i<=n-1;i++) printf("%d\n",ans[i]); 
	return 0;
}
