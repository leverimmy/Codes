#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXn 50002
#define MAXm 50002
using namespace std;
int n,m;
int indegree[MAXn],outdegree[MAXn],ans[MAXn];
bool flag=false;
struct line {
	int from,to;
} a[MAXm][2],b[MAXm];
void dfs(int k) {
	if(flag==true) return ;
	if(k>=m+1) {
		flag=true;
		for(int j=1; j<=n; j++)
			if(indegree[j]!=outdegree[j]) {
				flag=false;
				break;
			}
		if(flag==true) {
			for(int j=1; j<=m; j++) cout<<ans[j];
			cout<<endl;
		}
		return ;
	}
	for(int i=0; i<=1; i++) {
		indegree[a[k][i].to]++;
		outdegree[a[k][i].from]++;
		ans[k]=i;
		dfs(k+1);
		if(flag==true) return ;
		indegree[a[k][i].to]--;
		outdegree[a[k][i].from]--;
	}
}
inline int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
int main() {
	freopen("fantasy.in","r",stdin);
	freopen("fantasy.out","w",stdout);
	n=read();
	m=read();
	for(int i=1; i<=m; i++) {
		int x,y,z;
		x=read();
		y=read();
		z=read();
		a[i][0].from=x=a[i][1].from=x;
		a[i][0].to=y;
		a[i][1].to=z;
	}
	dfs(1);
	return 0;
}
/*
3 2
1 2 3
2 1 3
*/
