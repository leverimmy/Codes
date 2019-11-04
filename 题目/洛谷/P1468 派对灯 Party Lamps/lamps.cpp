#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 110

using namespace std;

int n, c, tmp, tot_on, tot_off, cnt;
int on[maxn], off[maxn];

vector<int>vec[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int map[8][6] =
{
	{1, 1, 1, 1, 1, 1}, //0
	{0, 0, 0, 0, 0, 0}, //1
	{1, 0, 1, 0, 1, 0}, //2
	{0, 1, 0, 1, 0, 1}, //3
	{1, 0, 1, 1, 0, 1}, //4
	{0, 1, 0, 0, 1, 0}, //1,4  //5
	{1, 1, 1, 0, 0, 0}, //2,4  //6
	{0, 0, 0, 1, 1, 1}  //3,4  //7
};

void solve(int len, int s[])
{
	int flag1 = 0;
	for(rgi i = 0; i <= len - 1; ++i)
	{
		int flag2 = 1;
		for(rgi j = 1; j <= tot_on; ++j)
		{
			if(map[s[i]][on[j] % 6] == 0)
			{
				flag2 = 0;
				break;
			}
		}
		if(flag2 == 0)
			continue;
		for(rgi j = 1; j <= tot_off; ++j)
		{
			if(map[s[i]][off[j] % 6] == 1)
			{
				flag2 = 0;
				break;
			}
		}
		if(flag2 == 0)
			continue;
		flag1 = 1;
		cnt++;
		for(rgi j = 1; j <= n; ++j)
			vec[cnt].push_back(map[s[i]][j % 6]);
	}
	if(!flag1)
		puts("IMPOSSIBLE");
}

int main()
{
	n = read();
	c = read();
	while(scanf("%d", &tmp))
	{
		if(tmp == -1)
			break;
		on[++tot_on] = tmp;
	}
	while(scanf("%d", &tmp))
	{
		if(tmp == -1)
			break;
		off[++tot_off] = tmp;
	}
	if(c == 0)
	{
		int s[] = {0};
		solve(1, s);
	}
	else if(c == 1)
	{
		int s[] = {0, 1, 2, 3, 4};
		solve(5, s);
	}
	else if(c == 2)
	{
		int s[] = {0, 1, 2, 3, 5, 6, 7};
		solve(7, s);
	}
	else if(c > 2)
	{
		int s[] = {0, 1, 2, 3, 4, 5, 6, 7};
		solve(8, s);
	}
	sort(vec + 1, vec + cnt + 1);
	for(rgi i = 1; i <= cnt; ++i)
	{
		for(rgi j = 0; j < vec[i].size(); ++j)
			cout << vec[i][j];
		cout << endl;
	}
	return 0;
}

