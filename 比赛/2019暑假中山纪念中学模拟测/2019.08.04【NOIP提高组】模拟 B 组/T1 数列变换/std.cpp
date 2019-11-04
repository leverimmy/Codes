#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 1000000 + 10;

int n, head, tail;
int a[N << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int Ceil(int n, int k)
{
	if(n % k)
		return n / k + 1;
	else
		return n / k;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = i;
	head = 0, tail = n;
	for(rgi k = 2; k <= n; ++k)
	{
		a[++tail] = a[head + Ceil(n, k) * k - (k - 1)];
		for(rgi i = head + Ceil(n, k) * k - (k - 1); i >= head + 1; i -= k)
			a[i] = a[i - k];
		head++;
	}
	for(rgi i = head + 1; i <= tail; ++i)
		printf("%d ", a[i]);
	return 0;
}

