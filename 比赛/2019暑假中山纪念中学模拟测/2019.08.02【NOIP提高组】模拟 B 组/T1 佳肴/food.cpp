#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#define ll long long
#define il inline
#define rgi register int
#define maxn 50

using namespace std;

const int oo = 0x3f3f3f3f;

int n, ans = oo;
int sour[maxn], bitter[maxn], out[maxn] = {0, 1}, vis[maxn] = {0, 1};

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int step, int cur_sour, int cur_bitter, int cur_ans)
{
	if(step == n + 1)
	{
		ans = min(ans, cur_ans);
		return;
	}
	dfs(step + 1, cur_sour, cur_bitter, cur_ans); //ฒปัก
	dfs(step + 1, cur_sour * sour[step], cur_bitter + bitter[step], abs(cur_sour * sour[step] - (cur_bitter + bitter[step]))); //ัก
}

int main()
{
//	freopen("testdata.in", "r", stdin);
//	freopen("testdata.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		sour[i] = read();
		bitter[i] = read();
	}
	for(rgi i = 1; i <= n; ++i)
	{
		swap(sour[i], sour[1]);
		swap(bitter[i], bitter[1]);
		dfs(2, sour[1], bitter[1], abs(sour[1] - bitter[1]));
		swap(sour[i], sour[1]);
		swap(bitter[i], bitter[1]);
	}
	printf("%d", ans);
	return 0;
}

