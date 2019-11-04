#include <cstdio>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int p, k, q = 1;

int main()
{
	scanf("%d %d", &p, &k);
	if(k == 1)
	{
		printf("YES\n");
		for(rgi i = 0; i < p; i++)
			printf("%d ", i);
	}
	else if(p == 2)
	{
		for(rgi i = 1; i <= k; i++)
			q *= p;
		printf("YES\n");
		for(rgi i = 0; i < q; ++i)
			for(rgi j = 0; j < i; ++j)
				printf("%d %d\n", i, j);
	}
	printf("NO");
	return 0;
}

