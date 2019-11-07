#include <bits/stdc++.h>
char s[10000];
int n; 
void solve(int l,int r){
	if (l>=r)return;
	std::swap(s[l],s[r]);
	for(int i=1;i<=n;++i)printf("%c",s[i]);printf("\n");
	solve(l+1,r-1);
}

int main(){
	freopen("17.in","r",stdin);
	freopen("17.out","w",stdout);
	scanf("%d%s",&n,s+1);
	solve(1,n);
	printf("\n");for(int i=1;i<=n;++i)printf("%c",s[i]);
	return 0;
}
