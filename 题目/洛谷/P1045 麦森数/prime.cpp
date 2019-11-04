#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 2010

using namespace std;

int p, cnt;
int base[maxn] = {1, 2}, res[maxn] = {1, 1};

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void mul(int ans[], int A[], int B[])
{
	int C[maxn] = {0};
	int x = 0;
	for(rgi i = 1; i <= 500; ++i)
		for(rgi j = 1; j <= 500; ++j)
			C[i + j - 1] += A[i] * B[j];
	for(rgi i = 1; i <= 500; ++i)
	{
		C[i + 1] += C[i] / 10;
		C[i] %= 10;
	}
	memcpy(ans, C, sizeof(C));
}

int main()
{
	p = read();
	printf("%d\n", (int)(log10(2) * p + 1));
	while(p)
	{
		if(p & 1)
			mul(res, res, base);
		mul(base, base, base);
		p >>= 1;
	}
	res[1] -= 1;
	for(rgi i = 500; i >= 1; --i)
	{
		cnt++;
		printf("%d", res[i]);
		if(cnt % 50 == 0)
			puts("");
	}
	return 0;
}
