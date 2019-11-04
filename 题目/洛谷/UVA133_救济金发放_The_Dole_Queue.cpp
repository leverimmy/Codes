#include <cstdio>
#include <cstring>

using namespace std;

int n, k, m;
int a[10010];

void init()
{
	for(int i = 1; i <= n; i++)
		a[i] = i;
}

int go(int p, int d, int t)
{
	while(t--)
	{
		do
		{
			p = (p + d + n - 1) % n + 1;
		}
		while(a[p]==0);
	}
	return p;
}

int main()
{
	while(scanf("%d %d %d", &n, &k, &m) == 3 && n && k && m)
	{
		int A = n, B = 1, left = n;
		init();
		while(left)
		{
			A = go(A, 1, k);
			B = go(B, -1, m);
			printf("%3d", A);
			left--;
			if(A != B)
			{
				printf("%3d", B);
				left--;
			}
			a[A] = a[B] = 0;
			if(left)
				printf(",");
		}
		printf("\n");
	}
	return 0;
}

