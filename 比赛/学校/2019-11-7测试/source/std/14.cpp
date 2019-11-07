#include <bits/stdc++.h>

using namespace std;

int p[10],n;

void solve()
{
	if (p[1] <= 2)
	{
		if (p[5] != 1)
			return;
	}
	else
		if (p[5] == 1)
			return;
	if (p[2] <= 2)
	{
		if (p[2] == 1)
			return;
	}
	if (p[3] <= 2)
	{
		if (p[1] != 5)
			return;
	}
	else if (p[1] == 5)
		return;
	if (p[4] <= 2)
	{
		if (p[3] == 1)
			return;
	}
	else
	 	if (p[3] != 1)
	 		return;
	if (p[5] == 2 || p[5] == 3 || p[5] == 1)
		return;
	if (p[4] == 1)
		return;
	for (int i = 1; i <= n; i++)
		printf("%d ",p[i]);
}

int main()
{
	freopen("14.in","r",stdin);
	freopen("14.out","w",stdout);
	n = 5;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	do
	{
		solve();
	}while(next_permutation(p + 1,p + 1 + n));
	
	return 0;
}
