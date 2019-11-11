#include <bits/stdc++.h>
#define ll long long
ll tmp,score;
int a,b,len[1000005];
char s[1000005];
ll sqr(int x){return (ll)x*x;}
int main(){
	freopen("cards.out","r",stdin);
	a=87984,b=97158;
	scanf("%lld%s",&score,s+1);
	s[0]='p';int n=std::strlen(s+1);
	for(int i=1;i<=n;++i){
		if (s[i]=='o')a--;
		if (s[i]=='x')b--;
		if (s[i]==s[i-1])len[i]=len[i-1]+1;
		else {
			len[i]=1;
			if (s[i-1]=='x')tmp-=sqr(len[i-1]);
			if (s[i-1]=='o')tmp+=sqr(len[i-1]);
		}
	}if (s[n]=='o')tmp+=sqr(len[n]);
	else tmp-=sqr(len[n]);
	//printf("%lld %d %d\n",tmp,a,b);
	if (tmp==score&&a==0&&b==0)printf("Accepted");
	else printf("Wrong Answer");
	return 0;
}
