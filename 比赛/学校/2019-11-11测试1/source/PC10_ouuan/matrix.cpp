#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int n, m;
string s;
vector<int> cnt;
vector<vector<int> > a;
ifstream fin("matrix.in");
ofstream fout("matrix.out");

int main()
{
	fin >> n >> m;
	
	a.resize(n + 1, vector<int>(m + 2, 0));
	
	for (int i = 1; i <= n; ++i)
	{
		fin >> s;
		for (int j = m; j >= 1; --j) a[i][j] = (s[j - 1] == '1' ? a[i][j + 1] + 1 : 0);
	}
	
	int ans = 0;
	
	for (int i = 1; i <= m; ++i)
	{
		cnt.assign(m + 1, 0);
		for (int j = 1; j <= n; ++j) ++cnt[a[j][i]];
		for (int j = m, sum = 0; j >= 1; --j)
		{
			sum += cnt[j];
			ans = max(ans, j * sum);
		}
	}
	
	fout << ans << endl;
	
	return 0;
}
