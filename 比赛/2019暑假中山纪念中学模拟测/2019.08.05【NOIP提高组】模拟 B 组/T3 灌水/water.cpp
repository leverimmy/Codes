#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 21;

int n, h, step;
ll ans;
bool state[N];
bool vis[1 << N];
int round[1 << N];
int kth[1 << N];
int s[1 << N];
char e[N][N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int H(bool A[21])
{
	int res = 0;
	for(rgi i = 1; i <= 20; ++i)
		res += (1 << i - 1) * A[i];
	return res;
}

int main()
{
	n = read(), h = read();
	for(rgi i = 1; i <= n; ++i)
		scanf("%s", e[i] + 1);
	for(rgi i = 1; i <= n; ++i)
		if(e[1][i] == '1')
		{
			state[i] = 1;
			round[1]++;
		}
	vis[H(state)] = 1;
	kth[H(state)] = 1;
	for(rgi day = 2; day <= h; ++day)
	{
		bool tmp[N] = {0};
		for(rgi i = 1; i <= n; ++i)
		{
			if(state[i])//odd
			{
				for(rgi j = 1; j <= n; ++j)
					if(e[i][j] == '1')
					{
						round[day]++;
						tmp[j] ^= 1;
					}
			}
			else//even
			{
				for(rgi j = 1; j <= n; ++j)
					if(e[i][j] == '1')
						round[day] += 2;
			}
		}
		for(rgi i = 1; i <= n; ++i)
			state[i] = tmp[i];
		if(vis[H(state)])
		{
			step = day;
			break;
		}
		vis[H(state)] = 1;
		kth[H(state)] = day;
	}
	if(step != 0)//有循环节
	{
		int cur = kth[H(state)];//last time
		cur++;
		//step this time
		for(rgi i = 1; i <= step; ++i)
			s[i] = s[i - 1] + round[i];//prefix sum
		h -= cur - 1;//减去前面不要的长度
		ans += s[cur - 1];//加上前面的贡献
		ans += (ll)h / (step - cur + 1) * (s[step] - s[cur - 1]); //循环了多少次循环节
		int left = h % (step - cur + 1); //余数
		ans += s[cur + left - 1] - s[cur - 1];//加上余数的贡献
		printf("%lld", ans);
	}
	else//没有循环节
	{
		for(rgi i = 1; i <= h; ++i)
			s[i] = s[i - 1] + round[i];
		printf("%d", s[h]);
	}
	return 0;
}

