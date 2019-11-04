#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 100010

using namespace std;

int n, len1, len2;
int a[maxn], f1[maxn], f2[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	while(scanf("%d", &a[++n]) != EOF);
	n--;
	f1[1] = f2[1] = a[1];
	len1 = len2 = 1;
	for(rgi i = 2; i <= n; ++i)
	{
		if(f1[len1] >= a[i])
			f1[++len1] = a[i];
		else
		{
			int pos = upper_bound(f1 + 1, f1 + len1 + 1, a[i], greater <int> ()) - f1; //find the first bigger
			f1[pos] = a[i];
		}
		if(f2[len2] < a[i])
			f2[++len2] = a[i];
		else
		{
			int pos = lower_bound(f2 + 1, f2 + len2 + 1, a[i]) - f2; //find the first not bigger
			f2[pos] = a[i];
		}
	}
	printf("%d\n%d", len1, len2);
	return 0;
}
