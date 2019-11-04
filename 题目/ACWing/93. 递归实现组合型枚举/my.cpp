#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int n, m, cnt;
vector <int> vec;
vector <vector <int> > ans;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int step)
{
	if(vec.size() > m || vec.size() + (n - step + 1) < m)
		return;
	if(step == n + 1)
	{
		ans.push_back(vec);
		return;
	}
	dfs(step + 1);
	vec.push_back(step);
	dfs(step + 1);
	vec.pop_back();
}

int main()
{
	n = read(), m = read();
	dfs(1);
	sort(ans.begin(), ans.end());
	for(rgi i = 0; i < ans.size(); ++i)
	{
		for(rgi j = 0; j < ans[i].size(); ++j)
			printf("%d ", ans[i][j]);
		puts("");
	}
	return 0;
}

