#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 100005;

int n, F;

int val[maxn], c[maxn], lp[maxn], pos[maxn];

long long ans;

int read(void)
{
	int s = 0, w = 1;
	char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') w = -1;
	for(; ch <= '9' && ch >= '0'; ch = getchar()) s = s * 10 + ch - '0';
	return s * w;
}

bool check(int l, int r)
{
	int len = r - l + 1;
	for(int i = l; i <= r; i++) if(val[i] != val[i + len + F]) return false;
	return true;
}	

int main()
{
	freopen("weapon.in", "r", stdin);
	freopen("weapon.out", "w", stdout);
	n = read(); F = read();
	if(n <= 100)
	{
		for(int i = 1; i <= n; i++) val[i] = read();
		for(int i = 1; i <= n; i++)
			for(int len = 1; i + (len << 1) + F - 1 <= n; len++)
				if(check(i, i + len - 1)) ans++;
		cout << ans << '\n';
	}
	else 
	{
		for(int i = 1; i <= n; i++) val[i] = c[i] = read();
		sort(c + 1, c + n + 1);
		int tot = unique(c + 1, c + n + 1) - c - 1;
		for(int i = 1; i <= n; i++) val[i] = lower_bound(c + 1, c + tot + 1, val[i]) - c;
		memset(pos, -1, sizeof(pos));
		for(int i = 1; i <= n; i++) 
		{
			lp[i] = pos[val[i]];
			pos[val[i]] = i;
		}
		for(int i = 1; i <= n; i++)
		{
			int lpos = lp[i];
			for(; lpos != -1; )
			{
				if(i - lpos < 1 + F)
				{
					lpos = lp[lpos];
					continue;
				}
				int trylen = i - lpos - F;
				int Max_Right = lpos + (trylen << 1) + F - 1;
				if(Max_Right > n) break;
				if(check(lpos, lpos + trylen - 1)) ans++;
				lpos = lp[lpos];
			}
		}
		cout << ans << '\n';
	}			
	return 0;
}
