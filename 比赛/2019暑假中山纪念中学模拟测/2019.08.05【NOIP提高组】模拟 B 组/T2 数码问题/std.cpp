#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 10000 + 10;
const int K = 1000 + 10;

int n, k;

struct fix
{
	int id_hang, id_lie;
	int _hang, _lie;
} cmd[K];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int Ceil(int num, int k)
{
	if(num % k == 0)
		return num / k;
	return num / k + 1;
}

int getx(int val)
{
	return Ceil(val, n);
}

int gety(int val)
{
	if(val % n == 0)
		return n;
	return val % n;
}

int main()
{
	n = read(), k = read();
	for(rgi i = 1; i <= k; ++i)
	{
		int val = read(), x = read(), y = read();
		int cur_x = getx(val), cur_y = gety(val);

		for(rgi j = 1; j <= i - 1; ++j)
		{
			if(cur_x == cmd[j].id_hang)
			{
				cur_y += cmd[j]._hang;
				if(cur_y % n == 0)
					cur_y = n;
				else
					cur_y %= n;
			}
			if(cur_y == cmd[j].id_lie)
			{
				cur_x += cmd[j]._lie;
				if(cur_x % n == 0)
					cur_x = n;
				else
					cur_x %= n;
			}


		}

		int ans = 0;
		cmd[i].id_hang = cur_x;
		cmd[i].id_lie = y;
		cmd[i]._hang = (y - cur_y + n) % n;
		cmd[i]._lie = (x - cur_x + n) % n;
		if(cmd[i].id_hang == 0)
			cmd[i].id_hang = n;
		if(cmd[i].id_lie == 0)
			cmd[i].id_lie = n;

		ans += cmd[i]._hang;
		ans += cmd[i]._lie;
		printf("%d\n", ans);
	}
	return 0;
}

