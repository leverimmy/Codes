#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 1000000 + 10;

int _next[N];
string s;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Get_Next(string str)
{
	int len = str.length(), j = 0, k = -1;
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

int main()
{
	while(cin >> s)
	{
		if(s == ".")
			break;
		int len = s.length();
		Get_Next(s);
		if(len % (len - _next[len]) == 0)
			printf("%d\n", len / (len - _next[len]));
		else
			puts("1");
		memset(_next, 0, sizeof(_next));
	}
	return 0;
}

