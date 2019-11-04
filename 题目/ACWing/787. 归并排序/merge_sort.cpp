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
int a[maxn], tmp[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void merge_sort(int q[], int l, int r)
{
	if(l >= r)
		return;
	int mid = (l + r) >> 1;
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);
	int k = 0, i = l, j = mid + 1;
	while(i <= mid && j <= r)
		if(q[i] <= q[j])
			tmp[k++] = q[i++];
		else
			tmp[k++] = q[j++];
	while(i <= mid)
		tmp[k++] = q[i++];
	while(j <= r)
		tmp[k++] = q[j++];
	for(rgi i = l, j = 0; i <= r; i++, j++)
		q[i] = tmp[j];
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	merge_sort(a, 1, n);
	for(rgi i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;
}

