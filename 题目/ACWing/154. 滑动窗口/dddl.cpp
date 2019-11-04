#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 1000010

using namespace std;

int n, k, cnt;
int a[maxn], out[maxn], out2[maxn];

struct node
{
	int val, id;
};

deque <struct node> q1, q2;//q1 -> max; q2 -> min

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	k = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	for(rgi i = 1; i <= n; ++i)
	{
		struct node tmp;
		tmp.id = i, tmp.val = a[i];
		while(!q1.empty() && q1.back().val > tmp.val)
			q1.pop_back();
		while(!q2.empty() && q2.back().val < tmp.val)
			q2.pop_back();
		q1.push_back(tmp);
		q2.push_back(tmp);
		while(!q1.empty() && tmp.id - q1.front().id + 1 > k)
			q1.pop_front();
		while(!q2.empty() && tmp.id - q2.front().id + 1 > k)
			q2.pop_front();
		cnt++;
		out[cnt] = q1.front().val;
		out2[cnt] = q2.front().val;
	}
	for(rgi i = k; i <= n; ++i)
		printf("%d ", out[i]);
	puts("");
	for(rgi i = k; i <= n; ++i)
		printf("%d ", out2[i]);
	return 0;
}

