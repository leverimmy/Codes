#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 1010
#define maxm 20010

using namespace std;

int N, V;
int v[maxn], w[maxn], s[maxn];
int f[maxn][maxm];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	N = read(), V = read();
	for(rgi i = 1; i <= N; ++i)
	{
		v[i] = read();
		w[i] = read();
		s[i] = read();
	}
	for(rgi i = 1; i <= N; ++i)
	{
		for(rgi j = 0; j < v[i]; ++j)
		{
//			deque <int> dq;
			int q[maxm] = {0};
			int head = 0, tail = 0;
			for(rgi k = 0; j + k * v[i] <= V; ++k)
			{
				while(head < tail && k - s[i] * v[i] > q[head])
					head++;
//				while(!dq.empty() && k - s[i]*v[i] > dq.front())
//					dq.pop_front();
				while(head < tail && f[i - 1][j + k * v[i]] - k * w[i] >= f[i - 1][j + q[tail - 1] * v[i]] - q[tail - 1]* w[i])
					tail--;
//				while(!dq.empty() && f[i - 1][j + k * v[i]] - k * w[i] >= f[i - 1][j + dq.back()*v[i]] - dq.back()*w[i])
//					dq.pop_back();
				q[tail++] = k;
//				dq.push_back(k);
				if(head < tail)
					f[i][j + k * v[i]] = f[i - 1][j + q[head] * v[i]] + (k - q[head]) * w[i];
//				if(!dq.empty())
//					f[i][j + k * v[i]] = f[i - 1][j + dq.front() * v[i]] + (k - dq.front()) * w[i];
			}
		}
	}
	printf("%d", f[N][V]);
	return 0;
}

