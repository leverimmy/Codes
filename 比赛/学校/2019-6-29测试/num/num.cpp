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
#define inf 0x3f3f3f3f
#define maxn 50

using namespace std;

int n, ans = inf, len, sum;
int a[maxn], a1[maxn];
char s[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int pos, int tot, int num, int sum)//the posth gap; left <- tot '+'s;the remain of num;total sum is sum;
{
	if(pos == len)//no gaps anymore
	{
		if(sum + num == n)
		{
			ans = min(ans, tot);
			return;
		}
		else
			return;
	}
	if(num >= n || sum >= n)//cut cut cut
		return;
	if(tot >= ans)//cut cut cut
		return;
	dfs(pos + 1, tot + 1, a[pos + 1], sum + num); //add a '+'
	dfs(pos + 1, tot, 10 * num + a[pos + 1], sum); //do not add a '+'
}

int main()
{
	scanf("%s %d", s + 1, &n);
	len = strlen(s + 1);
	for(rgi i = 1; i <= len; ++i)
		a1[i] = s[len - i + 1] - '0';
	for(rgi i = 1; i <= len; ++i)
	{
		a[i] = a1[len - i + 1];
		sum += a[i];
	}
	dfs(1, 0, a[1], 0);
	if(sum == n && n == 0)
		ans = 0;
	if(ans != inf)
		printf("%d", ans);
	else
		puts("-1");
	return 0;
}

