#include <bits/stdc++.h>
int n;char s[9000];
int solve(int l,int r){
	if (l>=r-1){
		if (s[l]==s[r])return 0;
		return -1;
	}
	int p=0;
	for(int i=r;i>l;i--)
		if (s[i]==s[l]){p=i;break;}
	if (p){
		int cnt=0;
		for(int i=p;i<r;++i){cnt++;std::swap(s[i],s[i+1]);}
		int d=solve(l+1,r-1);
		if (d==-1)return d;
		return d+cnt;
	}for(int i=l;i<r;++i)
		if (s[i]==s[r]){p=i;break;}
	if (p){
		int cnt=0;
		for(int i=p;i>l;i--){cnt++;std::swap(s[i],s[i-1]);}
		int d=solve(l+1,r-1);
		if (d==-1)return d;
		return d+cnt;
	}return -1;
}

int main(){
	freopen("reference.in","r",stdin);
	freopen("reference.out","w",stdout);
	scanf("%d%s",&n,s+1);
	int d=solve(1,n);
	if (d==-1){printf("Impossible");}
	else printf("%d",d);
	
	//printf("\n%s",s+1);
	return 0;
}
