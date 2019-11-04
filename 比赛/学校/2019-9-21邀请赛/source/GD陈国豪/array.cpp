# include <bits/stdc++.h>
# define imax(a,b) ((a)>(b))?(a):(b)
# define imin(a,b) ((a)<(b))?(a):(b)
# define LL long long
# define is(a) (a>='0'&&a<='9')
using namespace std;
int n;
inline void read(int &x)
{
	x=0;
	int f=0;
	char ch=getchar();
	for (; !is(ch); ch=getchar()) f|=(ch=='-');
	for (; is(ch); ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	x=(f)?-x:x;
}
const int maxn=1e5+5;
int a[maxn],num;
int main()
{
		freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	read(n);
	for (int i=1; i<=n; i++) read(a[i]);
	read(num);
	for (int i=1; i<=num; i++)
	{
		int p,k;
		read(p),read(k);
		int s=p,ans=0;
		for (int j=1; j<=n; j++)
		{
			p=p+a[s]+k;
			ans++;
			if (p>n) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}

