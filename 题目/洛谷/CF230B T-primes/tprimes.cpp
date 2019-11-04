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

ll n;
int book[maxn] = {0, 1};
ll prime[maxn];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void make_table()
{
	int point = 0;
	for(int i = 2; i < maxn; i++)
	{
		if(book[i] == 0)
		{
			prime[point] = i;
			point++;
		}
		for(int j = 0; j < point && i * prime[j] < maxn; j++)
		{
			book[i * prime[j]] = 1;
			if(i % prime[j] == 0)
				break;
		}
	}
}

int main()
{
	n = read();
	make_table();
	for(rgi i = 1; i <= n; ++i)
	{
		ll cur = read();
		bool flag = 0;
		ll sqrt_cur = ceil(sqrt(cur));
		if(sqrt_cur * sqrt_cur == cur && !book[sqrt_cur])
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

