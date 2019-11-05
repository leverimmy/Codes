#include <cstdio>
#include <cstring>
#define MAXN 20005

int n, ans, l;
char ch[MAXN];

int main()
{
	freopen("tea.in", "r", stdin);
	freopen("tea.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)	
	{
		int tot = 0;
		scanf("%s",ch), l = strlen(ch) - 1;
		for (int j = 0; j <= l; j++) 
		{
			if (ch[j] >= 'A' && ch[j] <= 'Z') ch[j] += 32;
			tot += ch[j] == 'q' || ch[j] == 'w' || ch[j] == 'e' || ch[j] == 'r';
		}
		ans += tot * 2 > (l + 1);
	}
	printf("%d", ans);
	return 0;
}
