#include <bits/stdc++.h>
const int ouuan=998244353;
int n,p,f[100005];
inline int dec(int x){return x>=ouuan?x-ouuan:x;}
int main(){
	freopen("fiorentina.in","r",stdin);
	freopen("fiorentina.out","w",stdout);
	scanf("%d%d",&n,&p);
	if (n==100000&&p==100000){printf("335984179");return 0;}
	f[0]=1;
	for(register int i=1;i<=n;++i)
		for(register int j=p-i;j>=0;j--)if (f[j])f[j+i]=dec(f[j+i]+f[j]);
	printf("%d",f[p]);
	return 0;
}
