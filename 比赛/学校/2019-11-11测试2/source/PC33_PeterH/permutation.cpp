#include<iostream>
#include<cstdio>
#include<cstdlib>
#define MAXn 100002
#define MAXans 1002
using namespace std;
int n;
int a[MAXn],tot,ans[MAXn],maxs[MAXn];
bool book[MAXans][MAXn];
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
int main() {
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	n=read();
	for(int i=1; i<=n; i++) {
		bool flag=0;
		a[i]=read();
		for(int j=1; j<=tot; j++)
			if(!book[j][a[i]]) {
				book[j][a[i]]=1,ans[i]=j,flag=1,maxs[j]=max(maxs[j],a[i]);
				break;
			}
		if(!flag) book[++tot][a[i]]=1,ans[i]=tot,maxs[tot]=a[i];
	}
	for(int i=1; i<=tot; i++)
		for(int j=1; j<=maxs[i]; j++)
			if(!book[i][j]) {
				printf("-1\n");
				return 0;
			}
	cout<<tot<<endl;
	for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
