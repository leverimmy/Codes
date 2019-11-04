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

int n;
int a[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void quick_sort(int a[], int l, int r)
{
	if(l >= r)
		return;
	int k = a[l], i = l - 1, j = r + 1;
	while(i < j)
	{
		do
			i++;
		while(a[i] < k);
		do
			j--;
		while(a[j] > k);
		if(i < j)
			swap(a[i], a[j]);
	}
	quick_sort(a, l, j);
	quick_sort(a, j + 1, r);
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	quick_sort(a, 1, n);
	for(rgi i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;
}

