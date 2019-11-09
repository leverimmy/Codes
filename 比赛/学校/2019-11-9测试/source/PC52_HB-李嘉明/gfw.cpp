#include <cstdio>
#include <iostream>
using namespace std;

int n,Hi[200000],length[200000];

int solve(int p){
	int i,maxl=0;
	for(i=p-1;i>-1;i--){
		if(Hi[i]<Hi[p]&&length[i]>maxl){
			maxl=length[i];
		}
	}
	return maxl+1;
}

int main(){//DP
	int i,j,maxl=1;
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>Hi[i];
	}
	for(i=0;i<n;){
		length[i]=1;
		for(j=i;j<n-1&&Hi[j+1]>Hi[j];j++){
			length[j+1]=length[j]+1;
		}
		i=j+1;
	}
	for(i=1;i<n;i++){
		length[i]=solve(i);
		if(length[i]>maxl){
			maxl=length[i];
		}
	}
	cout<<maxl;
	return 0;
}
