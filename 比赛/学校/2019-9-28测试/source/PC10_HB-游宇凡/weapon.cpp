#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, f, a[N], lsh[N], lshtot;
long long ans;

struct SuffixArray
{
	int cnt[N], sa[N], rk[N << 1], px[N], id[N << 1], ht[N], mn[N << 1][20], len[N];

	bool cmp(int x, int y, int w) { return id[x] == id[y] && id[x + w] == id[y + w]; }
	
	void build()
	{
		int m = lshtot - 1;
		for (int i = 1; i <= n; ++i) ++cnt[rk[i] = a[i]];
	    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	    for (int i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;
		
		for (int w = 1, p; w < n; w <<= 1, m = p)
	    {
	    	p = 0;
	        for (int i = n; i > n - w; --i) id[++p] = i;
	        for (int i = 1; i <= n; ++i) if (sa[i] > w) id[++p] = sa[i] - w;
	        memset(cnt, 0, sizeof(cnt));
	        for (int i = 1; i <= n; ++i) ++cnt[px[i] = rk[id[i]]];
	        for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	        for (int i = n; i >= 1; --i) sa[cnt[px[i]]--] = id[i];
	        swap(rk, id);
	        p = 0;
	        for (int i = 1; i <= n; ++i) rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
	    }
	    
	    for (int i = 1, k = 0; i <= n; ++i)
		{
		    if (k) --k;
		    while (a[i + k] == a[sa[rk[i] - 1] + k]) ++k;
		    ht[rk[i]] = mn[rk[i]][0] = k;
		}
		
		for (int i = 1; i <= 16; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				mn[j][i] = min(mn[j][i - 1], mn[j + (1 << (i - 1))][i - 1]);
			}
		}
		
		for (int i = 1; i <= n; ++i)
		{
			while ((1 << (len[i] + 1)) <= i)
			{
				++len[i];
			}
		}
	}
	
	int calc(int x, int y)
	{
		int l = rk[x];
		int r = rk[y];
		if (l > r) swap(l, r);
		++l;
		int length = len[r - l + 1];
		return min(mn[l][length], mn[r - (1 << length) + 1][length]);
	}
} lcp, lcs;

int main()
{
	freopen("weapon.in", "r", stdin);
	freopen("weapon.out", "w", stdout);
	
	scanf("%d%d", &n, &f);
	
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", a + i);
		lsh[i] = a[i];
	}
	
	sort(lsh + 1, lsh + n + 1);
	lshtot = unique(lsh + 1, lsh + n + 1) - lsh;
	
	for (int i = 1; i <= n; ++i) a[i] = lower_bound(lsh + 1, lsh + lshtot, a[i]) - lsh;
	
	lcp.build();
	
	reverse(a + 1, a + n + 1);
	lcs.build();
	
	for (int len = 1; len <= n / 2; ++len)
	{
		for (int i = len; i + len + f <= n; i += len)
		{
			int l = i;
			int r = i + len + f;
			int lcp_num = lcp.calc(l, r);
			int lcs_num = lcs.calc(n - l + 1, n - r + 1);
			l = max(i - len + 1, i - lcs_num + 1);
			r = min(i, i + lcp_num - len);
			if (r >= l) ans += r - l + 1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
