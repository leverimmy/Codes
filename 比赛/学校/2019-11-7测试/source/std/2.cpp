#include <bits/stdc++.h>

using namespace std;

int n,len;
char s[12][110];

int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		scanf("%s",s[i] + 1);
	len = strlen(s[1] + 1);
	for (int i = 1; i <= len; i++)
	{
		int t1 = 0,t2 = 0,t3 = 0,t4 = 0;
		for (int j = 1; j <= n; j++)
		{
			if (s[j][i] == 'A')
				t1++;
			if (s[j][i] == 'C')
				t2++;
			if (s[j][i] == 'G')
				t3++;
			if (s[j][i] == 'T')
				t4++;
		}
		int maxx = max(t1,max(t2,max(t3,t4)));
		if (t1 == maxx)
			printf("A");
		else if (t2 == maxx)
			printf("C");
		else if (t3 == maxx)
			printf("G");
		else if (t4 == maxx)
			printf("T");
	}
	
	
	return 0;
}
