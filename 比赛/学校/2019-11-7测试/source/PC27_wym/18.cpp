#include<bits/stdc++.h>
using namespace std;
int f[10010];
set<int>ctholly;
int find(int bas){
	if(f[bas]==bas)
		return bas;
	return f[bas]=find(f[bas]);
}
int main(){
	freopen("18.in","r",stdin);
	freopen("18.out","w",stdout);
	int n,m,t1,t2;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		f[i]=i;
	for(int i=1;i<=m;++i){
		cin>>t1>>t2;
		if(find(t1)==find(t2))
			continue;
		f[t1]=t2;
	}
	for(int i=1;i<=n;++i)
		ctholly.insert(find(i));
	cout<<ctholly.size();
	return 0;
}
