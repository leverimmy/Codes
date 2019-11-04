#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int tot, flag, ans[110];
char cur[110];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

const char s[][50] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "a", "both", "another", "first", "second", "third"};

int main()
{
	while(scanf("%s", cur) != EOF)
	{
		//int len = strlen(cur);
		//if(cur[len - 1] == '.')
		//	cur[len - 1] = '\0';
		for(rgi i = 1; i <= 27; ++i)
		{
			if(!strcmp(cur, s[i]))
			{
				if(i <= 20)
					ans[++tot] = i * i % 100;
				else
				{
					if(i == 21 || i == 23 || i == 24)
						ans[++tot] = 1;
					if(i == 22 || i == 25)
						ans[++tot] = 4;
					if(i == 26)
						ans[++tot] = 9;
				}
			}
		}
	}
	sort(ans + 1, ans + tot + 1);
	for(rgi i = 1; i <= tot; ++i)
	{
		if(ans[i] != 0)
			flag++;
		if(flag == 1)
			printf("%d", ans[i]);
		else if(flag > 1)
			printf("%.2d", ans[i]);
	}
	if(tot == 0)
		puts("0");
	return 0;
}

