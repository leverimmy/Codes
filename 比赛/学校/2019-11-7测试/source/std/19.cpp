#include <bits/stdc++.h>

using namespace std;

const int maxn = 10010;
int s,t,a,b,c,d;
int f1[maxn],f2[maxn],f3[maxn],f4[maxn];

int main()
{
	freopen("19.in","r",stdin);
	freopen("19.out","w",stdout);
	scanf("%d%d%d%d%d%d",&s,&t,&a,&b,&c,&d);
	f1[1] = f1[2] = f2[1] = f2[2] = f3[1] = f3[2] = f4[1] = f4[2] = 1;
	for (int i = 1; i <= 2; i++)
	{
		f1[i] %= a;
		f2[i] %= b;
		f3[i] %= c;
		f4[i] %= d;
	}
	for (int i = 3; i <= t; i++)
	{
		f1[i] = (f1[i - 1] + f1[i - 2]) % a;
		f2[i] = (f2[i - 1] + f2[i - 2]) % b;
		f3[i] = (f3[i - 1] + f3[i - 2]) % c;
		f4[i] = (f4[i - 1] + f4[i - 2]) % d;
	}
	for (int i = s; i <= t; i++)
		if (f1[i] != 0 && f2[i] != 0 && f3[i] != 0 && f4[i] != 0)
			printf("%d ",i);
	
	return 0;
}
