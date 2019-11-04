#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
int l[100001],r[100001],p[100001],v[100001];
int a[100001];
int ans[100001];
int minl,maxr;
int ans1[100001];
int find(int l,int r,int p,int v){
	int sum=0;
	for(int i=l;i<=r;i++){
		if(a[i]%p==v){
			sum++;
		}
	}
	return sum;
}
int getans(int l,int r,int v){//p same
	int sum=0;
	for(int i=l;i<=r;i++){
		if(ans1[i]==v){
			sum++;
		}
	}
	return sum;
}
int main(){
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool ok=0;
	cin>>l[1]>>r[1]>>p[1]>>v[1];
	for(int i=2;i<=m;i++){
		cin>>l[i]>>r[i]>>p[i]>>v[i];
		if(p[i]!=p[i-1]){
			ok=1;
		}else{
			minl=min(l[i],minl);
			maxr=max(r[i],maxr);
		}
	}
	if(ok=1){//如果p值相同，正常处理 
		for(int i=1;i<=m;i++){
			ans[i]=find(l[i],r[i],p[i],v[i]);
		}	
	}else{//否则特殊情况 
		for(int i=minl;i<=maxr;i++){
			ans1[i]=a[i]%p[1];//预处理出v
		}
		for(int i=1;i<=m;i++){
			ans[i]=getans(l[i],r[i],v[i]);
		}
	}
	for(int i=1;i<m;i++){
		cout<<ans[i]<<endl;
	}
	cout<<ans[m];
	return 0;
}
