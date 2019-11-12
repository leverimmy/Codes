#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n,a[1001000],tot[1001000],ans[1001000];

int main()
{
	freopen("permutation.in","r",stdin);     freopen("permutation.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)     scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++)
		{
			tot[a[i]]++;
			ans[i] = tot[a[i]];
		}
	int cnt = tot[1];
	for (int i = 2;i <= n;i++)
		if (tot[i] <= tot[i - 1])
			cnt += tot[i];
		else break ;
	if (cnt != n)    printf("-1\n");
	else {
		printf("%d\n",tot[1]);
		for (int i = 1;i <= n;i++)
			printf("%d ",ans[i]);
	}
}
