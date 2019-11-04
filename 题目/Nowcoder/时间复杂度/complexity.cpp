#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#define rgi register int
#define il inline
#define ll long long
#define maxn 110

using namespace std;

typedef pair<char, int> pci;

int T, siz;

pci stk[maxn];

int get_num(string number)
{
	int res = 0, len = number.length() - 1;
	for(rgi i = 0; i < len; ++i)
		res = res * 10 + number[i] - '0';
	return res;
}

int get_time(string time)
{
	if(time == "O(1)")
		return 0;
	int pos = time.find('^');
	string number = time.substr(pos + 1);
	//number.pop_back();
	return get_num(number);
}

bool vis(char ch)
{
	for(rgi i = 1; i <= siz; ++i)
		if(stk[i].first == ch)
			return 1;
	return 0;
}

int get_for(string x, string y)
{
	if(x == "n")
	{
		if(y == "n")
			return 0;
		else
			return -1;
	}
	else
	{
		if(y == "n")
			return 1;
		else
		{
			int a = get_num(x), b = get_num(y);
			if(a <= b)
				return 0;
			else
				return -1;
		}
	}
}

int main()
{
	cin >> T;
	while(T--)
	{
		int n;
		string str;
		cin >> n >> str;
		int expected_time = get_time(str);
		getline(cin, str);
		siz = 0;
		int found_time = 0;
		bool error = 0;
		while(n--)
		{
			getline(cin, str);
			if(str == "E")
			{
				if(siz)
					siz--;
				else
					error = 1;
			}
			else
			{
				string F, i, x, y;
				stringstream sin(str);
				sin >> F >> i >> x >> y;
				if(vis(i[0]))
					error = 1;
				else
				{
					int tm = get_for(x, y);
					if(tm >= 0 && stk[siz].second >= 0)
						tm += stk[siz].second;
					else
						tm = -1;
					siz++;
					stk[siz].first = i[0];
					stk[siz].second = tm;
					found_time = max(found_time, tm);
				}
			}
		}
		if(siz)
			error = 1;
		if(error)
			puts("ERR");
		else if(expected_time == found_time)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}

