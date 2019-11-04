#include <iostream>
#include <algorithm>
#include <set>
#define rgi register int

using namespace std;

const int N = 1e4 + 10;
const int inf = 1e6 + 10;

int n, cur;
int w[N], cnt[inf];

set <int> f[N];

void divide(int id, int x)
{
	for(rgi i = 1; i <= x / i; ++i)
		if(x % i == 0)
		{
			f[id].insert(i);
			f[id].insert(x / i);
		}
	for(set<int>::iterator it = f[id].begin(); it != f[id].end(); ++it)
		cnt[*it]++;
}

int main()
{
	cin >> n; for(rgi i = 1; i <= n; ++i) cin >> w[i];
	for(rgi i = 1; i <= n; ++i) divide(i, w[i]); cur = inf;
	for(rgi i = 1; i <= n; ++i)
	{
		while(cnt[cur] < i)	cur--;
		cout << cur << endl;
	}
	return 0;
}
