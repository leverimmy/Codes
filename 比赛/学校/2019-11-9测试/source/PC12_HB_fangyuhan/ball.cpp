#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXn 200002
using namespace std;
int n;
struct node {
	int x;
	double r;
} a[MAXn];
double ans[MAXn];
inline int read() {
	int sum=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) sum=(sum<<1)+(sum<<3)+(ch^'0'),ch=getchar();
	return sum*f;
}
bool cmp(const node &a,const node &b) {
	if(a.x<b.x) return 1;
	else return 0;
}
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();
	for(int i=1; i<=n; i++) a[i].x=read(),a[i].r=read();
	sort(a+1,a+n+1,cmp);
	ans[1]=a[1].r;
	for(int i=2; i<=n; i++) {
		ans[i]=0x7fffffff/3;
		for(int j=1; j<=i-1; j++) ans[i]=min((a[i].x-a[i-j].x)*(a[i].x-a[i-j].x)/(4*ans[i-j]),ans[i]);
		ans[i]=min(ans[i],a[i].r);
	}
	for(int i=1; i<=n; i++) printf("%.3lf\n",ans[i]);
	return 0;
}
/*
3
0 9
8 1
13 7
*/
