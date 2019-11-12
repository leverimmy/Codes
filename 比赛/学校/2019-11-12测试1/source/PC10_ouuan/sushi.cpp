#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
string s;
vector<int> a;
ifstream fin("sushi.in");
ofstream fout("sushi.out");

int main()
{
	int T;
	
	fin >> T;
	
	while (T--)
	{
		fin >> s;
		n = s.size();
		int bcnt = 0, rcnt = 0;
		for (int i = 0; i < n; ++i)
		{
			bcnt += s[i] == 'B';
			rcnt += s[i] == 'R';
		}
		
		if (bcnt == 0 || rcnt == 0)
		{
			puts("0");
			continue;
		}
		
		if (bcnt > rcnt)
		{
			for (int i = 0; i < n; ++i)
			{
				s[i] = (s[i] == 'B' ? 'R' : 'B');
			}
			swap(bcnt, rcnt);
		}
		s += s;
		
		a.clear();
		for (int i = 0; i < 2 * n; ++i) if (s[i] == 'B') a.push_back(i - a.size());
		
		int le = (bcnt + 1) / 2;
		while (le < bcnt && a[le] == a[le - 1]) ++le;
		
		ll sum = 0;
		for (int i = 0; i < bcnt; ++i) sum += abs(a[le - 1] - a[i]);
		ll ans = sum;
		
		for (int i = 0; i < bcnt; ++i)
		{
			sum += abs(a[bcnt + i] - a[le + i - 1]) - abs(a[i] - a[le + i - 1]);
			--le;
			while (le < (bcnt + 1) / 2)
			{
				do
				{
					sum += (ll) (a[le + i + 1] - a[le + i]) * (2 * le - bcnt);
					++le;
				} while (le < bcnt && a[le + i + 1] == a[le + i]);
			}
			ans = min(ans, sum);
		}
		
		fout << ans << endl;
	}
	
	return 0;
}
