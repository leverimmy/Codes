#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXn 100002
using namespace std;
int n,flag;
string s;
int ans1,ans2;
struct item {
	int wl,wc;
} a[MAXn];
struct item2 {
	int w,num;
} c[MAXn],l[MAXn];
bool book[MAXn];
bool cmp(const item2 &x,const item2 &y) {
	return x.w>y.w;
}
int main() {
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	cin>>n;
	cin>>s;
	if(s=="Cantor") flag=1;
	else flag=2;
	for(int i=1; i<=n; i++) cin>>a[i].wc>>a[i].wl,c[i].w=a[i].wc,c[i].num=i,l[i].w=a[i].wl,l[i].num=i;
	sort(c+1,c+n+1,cmp);
	sort(l+1,l+n+1,cmp);
	if(flag==1) {
		int pos1=1,pos2=1;
		for(int i=1; i<=n; i++) {
			if(i%2==1) {
				while(1) {
					if(book[c[pos1].num]==0) break;
					pos1++;
				}
				book[c[pos1].num]=1;
				ans1+=c[pos1].w;
			} else {
				while(1) {
					if(book[l[pos2].num]==0) break;
					pos2++;
				}
				book[l[pos2].num]=1;
				ans2+=l[pos2].w;
			}
		}
	} else {
		int pos1=1,pos2=1;
		for(int i=1; i<=n; i++) {
			if(i%2==0) {
				while(1) {
					if(book[c[pos1].num]==0) break;
					pos1++;
				}
				book[c[pos1].num]=1;
				ans1+=c[pos1].w;
			} else {
				while(1) {
					if(book[l[pos2].num]==0) break;
					pos2++;
				}
				book[l[pos2].num]=1;
				ans2+=l[pos2].w;
			}
		}
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
/*
7
Lagrange
4 1
3 1
2 1
1 1
1 2
1 3
1 4
*/
