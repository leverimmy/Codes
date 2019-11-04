#include <cstdio>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long
#define MOD 1000000007

using namespace std;

int Q;
int lx, rx, ly, ry, W, H, K;
int a[2020][2020], cnt[10000010];

void make_table(int l_x, int r_x, int l_y, int r_y)
{
	int x = r_x - l_x + 1, y = r_y - l_y + 1;
	for(int i = 1; i <= x; ++i)
		for(int j = 1; j <= y; ++j)
		{
			a[i][j] = (i + l_x - 1) ^ (j + l_y - 1);
			cnt[a[i][j]] = (cnt[a[i][j]] + 1) % MOD;
		}
}

int main()
{	scanf("%d", &Q);
	for(rgi i = 1; i <= Q; ++i)
	{
		scanf("%d %d %d %d %d %d %d", &lx, &rx, &ly, &ry, &W, &H, &K);
		if(K == 1)
			printf("1\n");
		else
		{
			make_table(lx, rx, ly, ry);
		}
	}
	return 0;
}
