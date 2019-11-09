#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
typedef long long ll;
const int N=2e5+5;
int n;
struct node{
	int x,r,id;double tr;
}a[N];
double ans[N];
int stk[N];
inline bool cmp(const node & a,const node & b){
	return a.x<b.x;
}
inline double calc(int i,int j){
	return ((ll)a[j].x-a[i].x)*((ll)a[j].x-a[i].x)*1.0/(4.0*a[i].tr);
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i].x=read(),a[i].r=read(),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	double pr=a[1].r;ans[a[1].id]=pr;a[1].tr=pr;
	int top=1;stk[top]=1;
	for(int i=2;i<=n;i++) {
		a[i].tr=a[i].r;
		for(int j=1;j<=min(top,100);j++) a[i].tr=min(a[i].tr,calc(stk[j],i));
		for(int j=max(min(top,100),top-100);j<=top;j++) a[i].tr=min(a[i].tr,calc(stk[j],i));
		while(top&&a[i].tr>=a[stk[top]].tr) top--;
		stk[++top]=i;ans[a[i].id]=a[i].tr;
	}
	for(int i=1;i<=n;i++) printf("%.3lf\n",ans[i]);
	return 0;
}
/*
3
0 9
8 1
13 7
*/
