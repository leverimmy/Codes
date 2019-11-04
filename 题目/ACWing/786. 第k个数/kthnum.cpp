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
#define maxn 100010

using namespace std;

int n, k;
int a[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int quick_sort(int q[], int l, int r, int pos)
{
	if(l >= r)
		return q[l];
	int cur = q[l], i = l - 1, j = r + 1;
	while(i < j)
	{
		do
			i++;
		while(q[i] < cur);
		do
			j--;
		while(q[j] > cur);
		if(i < j)
			swap(q[i], q[j]);
	}
	if(j - l + 1 >= pos)
		quick_sort(q, l, j, pos);
	else
		quick_sort(q, j + 1, r, pos - (j - l + 1));
}

int main()
{
	n = read(), k = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	printf("%d", quick_sort(a, 1, n, k));
	return 0;
}

