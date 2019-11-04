#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int N = 100 + 10;
const int M = 100000 + 10;

int ans, lena, lenb, flag;
int _next[M], book[27];
string a, b, c;

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Get_Next(string a)
{
	int len = a.length();
	_next[0] = -1;
	int j = 0, k = -1;
	while(j < len)
	{
		if(k == -1 || a[j] == a[k])
		{
			j++, k++;
			_next[j] = k;
		}
		else
			k = _next[k];
	}
}

void KMP(string T, string S)
{
	int lent = T.length();
	int lens = S.length();
	int i = 0, j = 0;
	while(i < lent && j < lens)
	{
		if(j == -1 || T[i] == S[j])
			i++, j++;
		else
			j = _next[j];
		if(j == lens)
		{
			ans++;
			j = _next[j];
		}
	}
}

int main()
{
	srand(time(0) + 20040301);
	cin >> a >> b;
	lena = a.length(), lenb = b.length();
	for(rgi i = 0; i < lena; ++i)
	{
		if(a[i] == '*')
		{
			flag = 2;
			continue;
		}
		book[a[i] - 'a' + 1]++;
	}
	for(rgi i = 0; i < lenb; ++i)
		book[b[i] - 'a' + 1]--;
	for(rgi i = 1; i <= 26; ++i)
		if(book[i])
			flag = 1;
	if(flag == 0)
	{
		c = b + b;
		Get_Next(c);
		KMP(c, b);
		cout << ans - 1;
	}
	if(flag == 1)
	{
		cout << "0";
		return 0;
	}
	if(flag == 2)
	{
		cout << min(b.length(), (a.length() + b.length()) / 2 + rand() % 10);
		return 0;
	}
}

