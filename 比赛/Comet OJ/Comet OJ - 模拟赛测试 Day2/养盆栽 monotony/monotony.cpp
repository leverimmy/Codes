#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 20 + 10;

int r, c, len, non_increase, non_decrease, cnt;
int a[N], vis[N], e[N][N];

vector <int> vec;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	r = read(), c = read();
	for(rgi i = 1; i <= r; ++i) for(rgi j = 1; j <= c; ++j) e[i][j] = read();
	if(r == 1 || c == 1)
	{
		if(r == 1)
			for(rgi i = 1; i <= c; ++i) a[i] = e[1][i], len = c;
		if(c == 1)
			for(rgi i = 1; i <= r; ++i) a[i] = e[i][1], len = r;
//		for(rgi i = 1; i <= len; ++i) printf("%d ", a[i]); puts("");
		for(rgi state = 0; state <= (1 << len) - 1; ++state)
		{
			non_decrease = non_increase = 0;
			vec.clear();
			for(rgi i = 1; i <= len; ++i)
			{
				if(state & (1 << i - 1))	continue;
				vec.push_back(a[i]);
			}
			for(rgi i = 1; i < vec.size(); ++i)
				if(vec[i - 1] >= vec[i])
				{
					non_increase = 1;
					break;
				}
			for(rgi i = 1; i < vec.size(); ++i)
				if(vec[i - 1] <= vec[i])
				{
					non_decrease = 1;
					break;
				}
			if(non_increase && !non_decrease)	cnt++;
			else if(!non_increase && non_decrease)	cnt++;
			else if(vec.size() == 1)	cnt++;
			else continue;
//			for(rgi i = 0; i < vec.size(); ++i)	printf("%d ", vec[i]);
//			puts("");
		}
		printf("%d", cnt);
	}
	else
	{	
		for(rgi row = 0; row <= (1 << r) - 1; ++row)
		{
			for(rgi column = 0; column <= (1 << c) - 1; ++column)
			{
				int ROW = 0, COLUMN = 0, flag = 1;
				int M[N][N] = {0};
				for(rgi i = 1; i <= r; ++i) if(row & (1 << i - 1)) continue; else
				{
					ROW++; COLUMN = 0;
					for(rgi j = 1; j <= c; ++j) if(column & (1 << j - 1)) continue; else
					{
						COLUMN++;
						M[ROW][COLUMN] = e[i][j];
					}
				}
				/*for(rgi i = 1; i <= ROW; ++i)
				{
					for(rgi j = 1; j <= COLUMN; ++j) printf("%d ", M[i][j]);
					puts("");
				}
				puts("");*/
				for(rgi i = 1; i <= ROW; ++i)
				{
					if(COLUMN == 1) break;
					non_decrease = non_increase = 0;
					for(rgi j = 2; j <= COLUMN; ++j)
					{
						if(M[i][j - 1] <= M[i][j])
						{
							non_decrease = 1;
							break;
						}
					}
					for(rgi j = 2; j <= COLUMN; ++j)
					{
						if(M[i][j - 1] >= M[i][j])
						{
							non_increase = 1;
							break;
						}
					}
					if(non_decrease && non_increase)	flag = 0;
					if(!non_decrease && !non_increase)	flag = 0;
					if(!flag)	break;
				}
				for(rgi i = 1; i <= COLUMN; ++i)
				{
					if(ROW == 1) break;
					non_decrease = non_increase = 0;
					for(rgi j = 2; j <= ROW; ++j)
					{
						if(M[j - 1][i] <= M[j][i])
						{
							non_decrease = 1;
							break;
						}
					}
					for(rgi j = 2; j <= ROW; ++j)
					{
						if(M[j - 1][i] >= M[j][i])
						{
							non_increase = 1;
							break;
						}
					}
					if(non_decrease && non_increase)	flag = 0;
					if(!non_decrease && !non_increase)	flag = 0;
					if(!flag)	break;
				}
				if(flag && ROW && COLUMN)	cnt++;
				/*else
				{
					for(rgi i = 1; i <= ROW; ++i)
					{
						for(rgi j = 1; j <= COLUMN; ++j) printf("%d ", M[i][j]);
						puts("");
					}
					puts("");
				}*/
			}
		}
		printf("%d", cnt);
	}
	return 0;
}
/*
1 10
1 2 3 4 5 6 7 8 9 10

1 8
5 6 1 2 3 4 7 8

3 3
1 2 5
7 6 4
9 8 3

*/
