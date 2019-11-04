#include<iostream>
#include<cstdio>
#include<algorithm>
#define imax(a,b) ((a>b)?(a):(b))
#define imin(a,b) ((a<b)?(a):(b))
#define is(ch) (ch>='0'&&ch<='9')
#define LL long long


using namespace std;

inline void read(int &x)
{
	x=0;char ch=getchar();bool p=0;
	for (;!is(ch);ch=getchar()) p|=ch=='-';
	for (; is(ch);ch=getchar())	x=(x<<3)+(x<<1)+(ch^48);
	x=p?-x:x;
}

int main()
{
	read(T);
	while (T--)	{
		read(n);
		int f = 1, x, y, z;
		for (int i = 1; i <= n; ++i)
		{
			read(x), read(y), read(z);
			if (f[x]) f = 0;
			f[x] = 1;
			if (f[y]) f = 0;
			f[y] = 0;
		}
		if (f) printf("Yes\n");else printf("No\n");
	}
	return 0;
}

