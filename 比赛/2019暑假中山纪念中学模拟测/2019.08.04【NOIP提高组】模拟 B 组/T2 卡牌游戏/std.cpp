#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register ll

using namespace std;

const int oo = 0x3f3f3f3f;
const ll N = 100000 + 10;

ll n, m, step, ans, minn = oo;
ll def[N], atk[N], x[N];
ll sum_def[N], sum_atk[N], sum_x[N];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	m = read(),n = read();
	for(rgi i = 1; i <= m; ++i)
	{
		char op[10];
		ll val;
		scanf("%s %lld", op, &val);
		if(op[0] == 'A')
			atk[++atk[0]] = val;
		else if(op[0] == 'D')
			def[++def[0]] = val;
	}
	for(rgi i = 1; i <= n; ++i)
		x[i] = read();
	sort(atk + 1, atk + atk[0] + 1);
	sort(def + 1, def + def[0] + 1);
	sort(x + 1, x + n + 1);
	for(rgi i = 1; i <= atk[0]; ++i)
		sum_atk[i] = sum_atk[i - 1] + atk[i];
	for(rgi i = 1; i <= def[0]; ++i)
		sum_def[i] = sum_def[i - 1] + def[i];
	for(rgi i = 1; i <= n; ++i)
		sum_x[i] = sum_x[i - 1] + x[i];
	atk[atk[0]+1] = oo;
	for(rgi i = 1; i <= n; ++i)
	{
		while(x[i] >= atk[step])
			step++;
		step--;
		minn = min(minn, step + n - i);
	}
	ans = sum_x[n] - sum_x[n - minn] - sum_atk[minn];
	if(minn >= atk[0] && n > m)
	{
		step = 1;
		for(rgi i = 1; i <= def[0]; ++i)
		{
			while(def[i] >= x[step])
				step++;
			x[step] = 0;
		}
		if(step <= n - minn)
			for(rgi i = 1; i <= n - minn; ++i)
				ans += x[i];
	}
	for(rgi i = 1; i < minn; ++i)
		ans = max(ans, sum_x[n] - sum_x[n - i] - sum_atk[i]);
	printf("%lld", ans);
	return 0;
}

