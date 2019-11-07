#include <bits/stdc++.h>

using namespace std;

const int maxn = 10;
int n,m,f[maxn],t;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[1] = 1;
	for (int i = 2; i <= 8; i++)
		f[i] = 2 * f[i - 1] + 1;
	t = n / m;
	if (n % m)
		t++;
	printf("%d\n",f[t]);
	
	return 0;
}
