#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 400000 + 10;

int len, cur, _next[N];
string str;

set <int> s;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Get_Next(string str)
{
	int len = str.length();
	int j = 0, k = -1;
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
	cin >> str;
	Get_Next(str);
	len = cur = str.length();
	while(_next[cur] != 0)
	{
		s.insert(_next[cur]);
		cur = _next[cur];
	}
	for(set <int> ::iterator it = s.begin(); it != s.end(); ++it)
		printf("%d ", *it);
	printf("%d", len);
	return 0;
}

