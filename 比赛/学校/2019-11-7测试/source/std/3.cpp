#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
int n,a[20],S[maxn],top;
char s[20];

void print(int x,int wei)
{
	if (x == 1 && wei == 2)
	{
		printf("shi ");
		return;
	}
	if (x == 1)
		printf("yi ");
	if (x == 2)
		printf("er ");
	if (x == 3)
		printf("san ");
	if (x == 4)
		printf("si ");
	if (x == 5)
		printf("wu ");
	if (x == 6)
		printf("liu ");
	if (x == 7)
		printf("qi ");
	if (x == 8)
		printf("ba ");
	if (x == 9)
		printf("jiu ");
	if (wei == 4)
		printf("qian ");
	if (wei == 3)
		printf("bai ");
	if (wei == 2)
		printf("shi ");
}

void du(int id)
{
	int last = 1;
	for (int i = 1; i <= top; i = last + 1)
	{
		last = i;
		if (S[i] != 0)
			print(S[i],top - i + 1);
		else
		{
			last = i;
			while (last + 1 <= top && S[last + 1] == 0)
				last++;
			if (last == top)
				break;
			else
				printf("ling ");
		}
	}
	if (id == 3)
		printf("yi ");
	if (id == 2)
		printf("wan ");
}

int main()
{
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	scanf("%s",s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		a[i] = s[i] - '0';
	reverse(a + 1,a + 1 + n);
	if (n >= 9)
	{
		top = 0;
		for (int i = min(12,n); i >= 9; i--)
			S[++top] = a[i];
		du(3);
	}
	if (n >= 5)
	{
		top = 0;
		for (int i = min(8,n); i >= 5; i--)
			S[++top] = a[i];
		du(2);
	}
	if (n >= 1)
	{
		top = 0;
		for (int i = min(n,4); i >= 1; i--)
			S[++top] = a[i];
		du(1);
	}
	
	return 0;
}
