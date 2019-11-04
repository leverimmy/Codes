#include <cstdio>
#include <cstring>
#include <cctype>
#include <set>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 400000 + 10;

int lenIN, _next[N];
char IN[N];

set <int> s;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Get_Next(char str[])
{
	int len = strlen(str), j = 0, k = -1;
	_next[0] = -1;
	while(j < len)
	{
		if(k == -1 || str[j] == str[k])
		{
			j++, k++;
			_next[j] = k;
		}
		else
			k = _next[k];
	}
}

void Debug(int l)
{
	for(rgi i = 1; i <= l; ++i)
		printf("%d ", _next[i]);
	puts("");
}

int main()
{
	while(scanf("%s", IN) != EOF)
	{
		lenIN = strlen(IN);
		Get_Next(IN);
		int cur = lenIN;
		while(_next[cur] != 0)
		{
			s.insert(_next[cur]);
			cur = _next[cur];
		}
		for(set <int> :: iterator it = s.begin(); it != s.end(); ++it)
			printf("%d ", *it);
		printf("%d\n", lenIN);
		s.clear();
		memset(_next, 0, sizeof(_next));
		memset(IN, '\0', sizeof(IN));
	}
	return 0;
}

