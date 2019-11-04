#include <cstdio>
#include <cstdlib>
using namespace std;
void swap(long long& a,long long& b)
{
	long long t=a;a=b;b=t;
}
long long solve(long long a,long long b)
{
	if(a<b) swap(a,b);
	if(a%b==0) return a/b+1;
	return solve(b,a%b)+(long long)a/b;
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	long long a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld",solve(a,b));
	//system("pause");
	return 0;
}
