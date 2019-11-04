#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long
#define maxn 100010

using namespace std;

int n, cnt;
string s[maxn], tar;

int main()
{
	scanf("%d", &n);
	for(rgi i = 1; i <= n; i++)
		cin >> s[i];
	cin >> tar;
	sort(s + 1, s + n + 1);
	for(rgi i = 1; i <= n; i++)
		if(s[i].find(tar, 0) == 0)
			cout << s[i] << endl;
	return 0;
}

