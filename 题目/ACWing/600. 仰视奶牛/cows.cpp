#include <cstdio>
#include <cctype>
#include <stack>
#define il inline
#define rgi register int
#define maxn 100010

using namespace std;

int n;
int a[maxn], out[maxn];

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct node
{
	int id, val;
};

stack <struct node> stk;

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	for(rgi i = 1; i <= n; ++i)
	{
		struct node tmp;
		tmp.id = i, tmp.val = a[i];
		while(!stk.empty() && tmp.val > stk.top().val)
		{
			out[stk.top().id] = i;
			stk.pop();
		}
		stk.push(tmp);
	}
	for(rgi i = 1; i <= n; ++i)
		printf("%d\n", out[i]);
	return 0;
}
