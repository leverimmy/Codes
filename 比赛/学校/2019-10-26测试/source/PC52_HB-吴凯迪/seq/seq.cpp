#include<bits/stdc++.h>

long long cnt;
void GCD(long long a,long long b)
{
	if(b==0) return;
	cnt += a/b;
	GCD(b,a%b);
}

signed main(void)
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	
	long long a,b;
	std::cin>>a>>b;
	
	if(a < b) std::swap(a,b);
	
	GCD(a,b);
	
	printf("%lld\n", cnt+1);
	
	return 0;
}
