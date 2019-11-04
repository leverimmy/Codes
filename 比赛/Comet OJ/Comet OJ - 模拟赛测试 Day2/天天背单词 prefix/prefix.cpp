#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;

int n, k, cnt = oo, a[N], vis[N];
string ans, my, words[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int x, int tot, int cur_ans)
{
	cout << ans << endl;
	if(vis[x])	return;
	vis[x] = 1;
	if(ans == my)
	{
		cnt = min(cnt, ++cur_ans);
		return;
	}
	if(tot == k + 1 || x == n + 1)	return;
	for(rgi i = 1; i <= n; ++i)
	{
		dfs(i, tot, ++cur_ans);
		string tmp = ans;
		ans = ans + words[i];
		dfs(i, tot + 1, ++cur_ans);
		ans = tmp;		
	}
	vis[x] = 0;
}

int main()
{
	n = read(), k = read();
	for(rgi i = 1; i <= n; ++i)
		cin >> words[i];
	cin >> my;
	for(rgi i = 1; i <= n; ++i) a[i] = i;
	for(rgi i = 1; i <= n; ++i)
		dfs(i, 0, 0);	
	printf("%d", cnt);
	return 0;
}
/*
5 3
a
b
c
d
e
cad

*/
