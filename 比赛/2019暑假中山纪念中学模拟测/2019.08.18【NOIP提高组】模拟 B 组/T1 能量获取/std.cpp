#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int N = 1000 + 10;
const int M = 1000 + 10;

int n, ans;
int F[N], C[N], W[N];

struct node
{
	int id, w;
} Node[M << 1];

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct node a, struct node b)
{
	return a.w < b.w;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		F[i] = read();
		Node[i].w = read();
		C[i] = read();
		Node[i].id = i;
	}
	sort(Node + 1, Node + n + 1, cmp);
	for(rgi i = 1; i <= n; ++i)
	{
		int flag = 0;
		for(rgi j = Node[i].id; j; j = F[j])
			if(C[j] < Node[i].w)
			{
				flag = 1;
				break;
			}
		if(flag)
			continue;
		for(rgi j = Node[i].id; j; j = F[j])
			C[j] -= Node[i].w;
		ans++;
	}
	printf("%d", ans);
	return 0;
}

