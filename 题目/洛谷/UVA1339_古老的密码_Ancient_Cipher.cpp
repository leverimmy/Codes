#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char a[110], b[110];
int lena, lenb;
int cnta[27], cntb[27];

int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	while(scanf("%s%s", a, b) == 2)
	{
		int flag = 1;
		lena = strlen(a);
		lenb = strlen(b);
		for(int i = 0; i < lena; i++)
			cnta[a[i] - 'A']++;
		for(int i = 0; i < lenb; i++)
			cntb[b[i] - 'A']++;
		sort(cnta, cnta + 26);
		sort(cntb, cntb + 26);
		for(int i = 0; i < 26; i++)
		{
			if(cnta[i] != cntb[i])
			{
				flag = 0;
				break;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
		memset(a, '\0', sizeof(a));
		memset(b, '\0', sizeof(b));
		memset(cnta, '\0', sizeof(cnta));
		memset(cntb, '\0', sizeof(cntb));
	}
	return 0;
}
