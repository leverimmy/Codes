#include <bits/stdc++.h>
int n,a[100000];
int main(){
	freopen("15.in","r",stdin);
	freopen("15.out","w",stdout);
	scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int sel=1;
	for(int i=1;i<=n;++i)if(a[i]>a[sel])sel=i;
	printf("%d %d",a[sel],sel-1); 
	return 0;
}
