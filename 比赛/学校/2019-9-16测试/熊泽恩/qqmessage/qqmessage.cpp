#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <iostream>
#include <string>
#define il inline
#define rgi register int
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1000 + 10;

int n, len0;
string name, info[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
//	freopen("qqmessage.in", "r", stdin);
//	freopen("qqmessage.out", "w", stdout);
	cin >> name; name = " " + name + " "; len0 = name.length();
	while(getline(cin, info[++n])){}
	sort(info + 1, info + n + 1);
	for(rgi i = 1; i <= n; ++i)
		if(info[i].find(name) != -1)
		{
			int len = info[i].length();
			for(rgi j = 19 + len0; j < len; ++j)
				cout << info[i][j];
			cout << endl;
		}
	return 0;
}
/*
Ahalei
2010-11-02 22:01:55 Ahalei 886.
2010-08-03 09:10:45 BigL What?
2010-11-02 21:45:09 Ahalei How are you?
2010-11-02 21:44:32 PGDN I'm OK!
2010-11-02 21:45:19 Ahalei what do you want to do?
2009-10-25 06:00:35 PGDN O my God!
*/
