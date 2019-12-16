#include<bits/stdc++.h>
using namespace std;
int n,m;
char ch[100002];
int a[100002];
int hash[100002];
int hash2[100002];
int sum(int l,int r){
	return hash[r]-hash[l];
}
int main(){
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	cin>>n>>m>>ch;
	for(int i=0;i<n;i++){
		a[i+1]=ch[i]-'a'+1;
		hash[i+1]=a[i+1]*a[i];
		hash2[i+1]=a[i+1]+hash2[i];
	}
	hash[1]=a[1]*a[n];
	for(int i=1;i<=n;i++){
		hash[i]+=hash[i-1];
	}
	while(m--){
		int x,y;
		int sig=1;
		cin>>x>>y;
		if(x==y){
			cout<<1<<'\n';
			continue;
		}
		if(x>y){
			swap(x,y);
			sig=0;
		}
		int k=0;
		while(y+(1<<k)<=n){
			k++;
		}
		while(k--){
			if(sum(x,x+(1<<k))==sum(y,y+(1<<k))&&hash2[x+(1<<k)]-hash2[x-1]==hash2[y+(1<<k)]-hash2[y-1]){
				x+=(1<<k);
				y+=(1<<k);
			}
		}
		cout<<((a[x+1]<=a[y+1])^sig)<<'\n';
	}
	return 0;
}
