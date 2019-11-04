#include <cstdio>
#include <cstring>
#include <algorithm>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int a[4];

int main()
{
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	scanf("%d %d %d", &a[1], &a[2], &a[3]);
	sort(a + 1, a + 4);
	if(a[3] == a[1] + 2)
		printf("0\n");
	else if(a[3] == a[2] + 2 || a[2] == a[1] + 2)
		printf("1\n");
	else
		printf("2\n");
	printf("%d\n", max(a[3] - a[2], a[2] - a[1]) - 1);
	return 0;
}

