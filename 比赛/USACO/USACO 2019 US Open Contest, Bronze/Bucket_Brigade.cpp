#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define rgi register int

using namespace std;

struct ppp
{
	int x, y, step;
} q[105];

bool book[15][15];
char s[15];
int bx, by, lx, ly, head, tail;

const int nxt[4][2] = {{0, 1}, {1, 0}, {0, -1}, { -1, 0},};

int main()
{
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);
	for(rgi i = 1; i <= 10; ++i)
	{
		scanf("%s", s);
		for(rgi j = 0; j < 10; ++j)
		{
			if(s[j] == 'B')
			{
				bx = i;
				by = j + 1;
			}
			if(s[j] == 'L')
			{
				lx = i;
				ly = j + 1;
			}
			if(s[j] == 'R')
				book[i][j + 1] = 1;
		}
	}
	head = 1;
	tail = 1;
	q[tail].x = lx, q[tail].y = ly;
	book[lx][ly] = 1;
	++tail;
	while(head < tail)
	{
		int tx, ty;
		for(rgi i = 0; i <= 3; ++i)
		{
			tx = q[head].x + nxt[i][0];
			ty = q[head].y + nxt[i][1];
			if(tx == bx && ty == by)
			{
				printf("%d\n", q[head].step);
				return 0;
			}
			if(book[tx][ty])
				continue;
			if(tx < 1 || tx > 10 || ty < 1 || ty > 10)
				continue;
			book[tx][ty] = 1;
			q[tail].x = tx, q[tail].y = ty, q[tail].step = q[head].step + 1;
			++tail;
		}
		++head;
	}
	return 0;
}

