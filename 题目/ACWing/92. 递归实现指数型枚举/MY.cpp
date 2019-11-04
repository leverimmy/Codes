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

int n;
vector <int> vec;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int step)
{
	if(step == n + 1)
	{
		for(vector <int> :: iterator it = vec.begin(); it != vec.end(); ++it)
			printf("%d ", *it);
		puts("");
		return;
	}
	dfs(step + 1);
	vec.push_back(step);
	dfs(step + 1);
	vec.pop_back();
}

int main()
{
	n = read();
	dfs(1);
	return 0;
}

