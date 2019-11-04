#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 500000 + 10;

int m, n;
int a[N], tmp[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Merge_Sort(int q[], int l, int r)
{
	if(l >= r)
		return;
	int mid = l + r >> 1;
	Merge_Sort(q, l, mid);
	Merge_Sort(q, mid + 1, r);
	int i = l, j = mid + 1, k = 0;
	while(i <= mid && j <= r)
		if(q[i] <= q[j])
			tmp[k++] = q[i++];
		else
			tmp[k++] = q[j++], m -= mid - i + 1;
	while(i <= mid)
		tmp[k++] = q[i++];
	while(j <= r)
		tmp[k++] = q[j++];
	for(rgi i = l, j = 0; i <= r; ++i, ++j)
		q[i] = tmp[j];
}

bool check(int q[], int l, int r)
{
	for(rgi i = l + 1; i <= r; ++i)
		if(q[i] < q[i - 1])
			return 0;
	return 1;
}

int main()
{
	m = read(), n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
//	printf("%d", ans);
	if(check(a, 1, n))
		printf("%d", m);
	else
	{
		Merge_Sort(a, 1, n);
		if(m < 0)
			puts("NH3 is unlucky");
		else
			printf("%d", m);
	}
	return 0;
}

