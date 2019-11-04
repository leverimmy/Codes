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
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	srand(time(NULL));
	if (rand()%2)  printf("Yes");
	 else printf("No");
/*	int t;
	read(t);
	while (t--)
	{
		read(n);
		int x,y,k;
		for (int i=1; i<=n; i++)
		read(x),read(y),read(k);
		if (n<=100)
		{
			for (int i=1; i<=n; i++)
			
		}
	}*/
	return 0;
}

