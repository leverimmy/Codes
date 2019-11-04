#include <cstdio>
#include <algorithm>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

ll T, N, L, R, X, K, x, y, flag = 1;
ll dis, level, speed, cnt, last;

int main()
{
	scanf("%d %d %d %d %d %d", &T, &N, &L, &R, &X, &K);
	level = 1;
	speed = L;
	for(rgi i = 1; i <= T; i++)
	{
		scanf("%d %d", &x, &y);
		if(x == 0)
		{
			if(level == N)
			{
				flag = 0;
				break;
			}
			else
			{
				level++;
				speed = L;
			}
		}
		else if(x == 1)
		{
			if(level == 1)
			{
				flag = 0;
				break;
			}
			else
			{
				level--;
				speed = R;
			}
		}
		if(y == 1)
			speed = min(R, speed + X);
		if(speed == R)
			cnt++;
		else
			cnt = 0;
		dis += speed * level;
		if(cnt >= K)
			break;
	}
	if(flag)
		printf("%lld", dis);
	else
		printf("-1");
	return 0;
}

