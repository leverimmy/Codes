#include<cstdio>
#define ri register int
#define rl register long long int
#define rc register char
#define in inline
#define ll long long int
#define gc getchar
#define absl(a) (((a)<0)?(-(a)):(a))
#define N 1000
in ll read()
{
	rl x=0;
	rc ch=gc();
	while(ch<'0' || ch>'9')
	{
		ch=gc();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0',ch=gc();
	}
	return x;
}
ll a1,a2,ans;
void work(ll a,ll b)
{
	if(b==0)
	{
		++ans;
		return;
	}
	ans+=a/b,work(b,a%b);
	return;
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	a1=read(),a2=read();
	if(a2>a1)
	{
		ri t=a1;
		a1=a2,a2=t;
	}
	work(a1,a2);
	printf("%lld",ans);
	return 0;
}
