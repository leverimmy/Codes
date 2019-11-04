#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

char ch;
string cur_p, s;
map <string, string> p;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)	putchar('-'), x = -x;
	if(x > 9)	write(x / 10);
	putchar(x % 10 + 48);
}

string find(string x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
	cin >> ch;
	while(ch != '$')
	{
		string s;
		cin >> s;
		if(ch == '#')
		{
			cur_p = s;
			if(p[s] == "")
				p[s] = s;
		}
		else if(ch == '+')
			p[s] = cur_p;
		else
			cout << s << ' ' << find(s) << endl;
		cin >> ch;
	}
	return 0;
}
