#include <cstdio>
#include <cstring>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <set>
#include <string>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

int n;
set <string> s;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		string cmd, str;
		cin >> cmd;
		if(cmd == "add")
		{
			getline(cin, str);
			s.insert(str);
		}
		else if(cmd == "find")
		{
			getline(cin, str);
			if(s.count(str))
				puts("yes");
			else
				puts("no");
		}
	}
	return 0;
}

