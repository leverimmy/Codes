#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 250;

int n;
int a[N], no[N];
char op[N];
double e[N], ans;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int cur, double cur_prob)
{
	if(cur == n + 1)
	{
		int tmp = a[1];
		for(rgi i = 1; i <= n; ++i)
		{
			if(no[i])
				continue;
			if(op[i] == '&')
				tmp = tmp & a[i + 1];
			else if(op[i] == '|')
				tmp = tmp | a[i + 1];
			else if(op[i] == '^')
				tmp = tmp ^ a[i + 1]; 
		}
		ans += cur_prob * tmp;
		return;
	}
	dfs(cur + 1, cur_prob * (1 - e[cur]));
	no[cur] = 1;
	dfs(cur + 1, cur_prob * e[cur]);
	no[cur] = 0;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n + 1; ++i)
		a[i] = read();
	for(rgi i = 1; i <= n; ++i)
	{
		char tmp[10];
		scanf("%s", tmp);
		op[i] = tmp[0];
	}
	for(rgi i = 1; i <= n; ++i)		
		scanf("%lf", &e[i]);
	dfs(1, 1);
	printf("%.4lf", ans);
	return 0;
}

