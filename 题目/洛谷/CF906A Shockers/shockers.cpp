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
#define maxn 100010

using namespace std;

int n, flag, len, ans, cur;
int book[50], a[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void check()
{
	int tot = 0;
	for(rgi j = 1; j <= 26; ++j)
	{
		if(book[j] == 0)
			tot++;
	}
	if(tot == 1)
		flag = 1;
}

int main()
{
	n = read();
	for(rgi i = 1; i < n; ++i)
	{
		char cmd[5] = {'\0'};
		char s[maxn] = {'\0'};
		scanf("%s %s", cmd, s + 1);
		len = strlen(s + 1);
		for(rgi j = 1; j <= len; ++j)
			a[j] = s[j] - 'a' + 1;
		if(cmd[0] == '.')
		{
			if(flag)
				continue;
			for(rgi j = 1; j <= len; ++j)
				book[a[j]] = -1;
		}
		else if(cmd[0] == '?')
		{
			if(flag)
			{
				ans++;
				continue;
			}
			for(rgi j = 1; j <= len; ++j)
				book[a[j]] = -1;
		}
		else if(cmd[0] == '!')
		{
			if(flag)
			{
				ans++;
				continue;
			}
			int yes[maxn] = {0};
			for(rgi j = 1; j <= len; ++j)
				yes[a[j]] = 1;
			for(rgi j = 1; j <= 26; ++j)
				if(!yes[j])
					book[j] = -1;
		}
		if(!flag)
			check();
	}
	printf("%d", ans);
	return 0;
}

