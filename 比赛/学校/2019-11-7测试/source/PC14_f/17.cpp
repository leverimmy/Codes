#include<bits/stdc++.h>

int len;
char s[10000];
signed main(void)
{
	freopen("17.in","r",stdin);
	freopen("17.out","w",stdout);
	
	scanf("%d%s", &len,s);
	for(int i=0;(i+1<<1)<len;i++){
		std::swap(s[i],s[len-i-1]);
		printf("%s\n", s);
	}
	
	printf("\n%s\n", s);
	
	return 0;
}
