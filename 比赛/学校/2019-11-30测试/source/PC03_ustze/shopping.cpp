#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n;
char s[105];
struct node{
	int x,y;
}a[N];
int vis[N][N];
pair<int,int> ans;
pair<int,int> f[N][N],g[N][N];
pair<int,int> operator + (pair<int,int> a,pair<int,int> b){
	return make_pair(a.first+b.first,a.second+b.second);
}
inline bool cmp(const node & a,const node & b){
	if(a.x!=b.x) return a.x>b.x;
	return a.y<b.y;
}
pair<int,int> dfs(int i,int j,int k){
	if(i>n) return make_pair(0,0);
	if(vis[i][j]) return f[i][j];
	vis[i][j]=1;
	pair<int,int> res(0,0);
	if(k==i) {
		if(j>0) res=max(res,make_pair(a[i].y,a[i+1].x)+dfs(i+2,j-1,k+2));
		res=max(res,dfs(i+1,j,k));
	}else {
		if(j>0) res=max(res,make_pair(a[i].y,a[k].x)+dfs(i+1,j-1,k+1));
		res=max(res,dfs(i+1,j,k));
	}
	return f[i][j]=res;
}
map<pair<int,int> ,int> mp;
int dfs(int i,int j){
	if(i>n){
		if(j==0) return 0;
		return -1000000;
	}
	if(j<0) return -1000000;
	pair<int,int> t(i,j);
	if(mp.find(t)!=mp.end()) return mp[t];
	mp[t]=max(dfs(i+1,j)+a[i].x,dfs(i+1,j-a[i].y));
	return mp[t];
} 
inline void print(pair<int,int> x) {
	printf("%d %d\n",x.second,x.first);
}
int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	if(s[1]!='C') ans=dfs(1,(n+1)/2,1);
	else ans=dfs(2,n/2,2)+make_pair(0,a[1].x);
	memset(vis,0,sizeof(vis));
	int res=dfs(1,ans.first);
	printf("%d %d",res,ans.first);
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
