#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define il inline
#define ll long long
#define rgi register ll
#define maxn 1000010

using namespace std;

ll n, ans;
ll A[maxn], B[maxn], C[maxn];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n + 1; ++i)
		A[i] = read();
	for(rgi i = 1; i <= n; ++i)
		B[i] = read();
	for(rgi i = 1; i <= n + 1; ++i)
	{
		if(B[i] + C[i] >= A[i])//defeat all
		{
			ans += A[i];
			if(C[i] >= A[i])
				C[i + 1] = B[i];
			else
				C[i + 1] = B[i] + C[i] - A[i];
		}
		else//not defeat all
			ans += (B[i] + C[i]);
	}
	printf("%lld", ans);
	return 0;
}

