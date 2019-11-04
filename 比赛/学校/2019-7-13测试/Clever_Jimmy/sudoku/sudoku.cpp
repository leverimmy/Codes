#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int T;
int e[110][10][10];
int Row_Exist[110][10][10];//ÐÐ
int Column_Exist[110][10][10];//ÁÐ
int Block_Exist[110][10][10];//Block_Exist[i][j] -> block i, number j

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int findblock(int x, int y)
{
	int s = (x - 1) / 3;
	int t = (y - 1) / 3;
	return t * 3 + s + 1;
}

void copy(int id)
{
	for(rgi i = 1; i <= 9; ++i)
		for(rgi j = 1; j <= 9; ++j)
		{
			e[id][i][j] = e[id - 1][i][j];
			Row_Exist[id][i][j] = Row_Exist[id - 1][i][j];
			Column_Exist[id][i][j] = Column_Exist[id - 1][i][j];
			Block_Exist[id][i][j] = Block_Exist[id - 1][i][j];
		}
}

void In()
{
	char temp[50];
	for(rgi i = 1; i <= 19; ++i)
	{
		if(i & 1)
			scanf("%s\n", temp);
		else
			scanf("|%d|%d|%d|%d|%d|%d|%d|%d|%d|\n", &e[0][i / 2][1], &e[0][i / 2][2], &e[0][i / 2][3], &e[0][i / 2][4], &e[0][i / 2][5], &e[0][i / 2][6], &e[0][i / 2][7], &e[0][i / 2][8], &e[0][i / 2][9]);
	}
	for(rgi i = 1; i <= 9; ++i)
		for(rgi j = 1; j <= 9; ++j)
		{
			int cur_val = e[0][i][j];
			Row_Exist[0][i][cur_val] = 1;
			Column_Exist[0][j][cur_val] = 1;
			Block_Exist[0][findblock(i, j)][cur_val] = 1;
		}
}

void Insert(int id, int x, int y, int val)
{
	copy(id);
	int cur_block = findblock(x, y);
	if(e[id][x][y])
	{
		puts("Error!");
		return;
	}
	if(Row_Exist[id][x][val])
	{
		puts("Error:row!");
		return;
	}
	if(Column_Exist[id][y][val])
	{
		puts("Error:column!");
		return;
	}
	if(Block_Exist[id][cur_block][val])
	{
		puts("Error:square!");
		return;
	}
	puts("OK!");
	e[id][x][y] = val;
	Row_Exist[id][x][val] = 1;
	Column_Exist[id][y][val] = 1;
	Block_Exist[id][findblock(x, y)][val] = 1;
}

void Delete(int id, int x, int y)
{
	copy(id);
	if(!e[id][x][y])
	{
		puts("Error!");
		return;
	}
	puts("OK!");
	int cur_val = e[id][x][y];
	e[id][x][y] = 0;
	Row_Exist[id][x][cur_val] = 0;
	Column_Exist[id][y][cur_val] = 0;
	Block_Exist[id][findblock(x, y)][cur_val] = 0;
}

void Query(int id, int x, int y)
{
	copy(id);
	int cnt = 0;
	int f[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	if(e[id][x][y])
	{
		puts("Error!");
		return;
	}
	for(rgi i = 1; i <= 9; ++i)
	{
		if(Row_Exist[id][x][i])
			f[i] = 0;
		if(Column_Exist[id][y][i])
			f[i] = 0;
		if(Block_Exist[id][findblock(x, y)][i])
			f[i] = 0;
	}
	for(rgi i = 1; i <= 9; ++i)
		if(f[i])
			cnt++;
	printf("%d\n", cnt);
	for(rgi i = 1; i <= 9; ++i)
		if(f[i])
			printf("%d\n", i);
}

void Print(int id)
{
	copy(id);
	for(rgi i = 1; i <= 19; ++i)
	{
		if(i & 1)
			puts("+-+-+-+-+-+-+-+-+-+");
		else
			printf("|%d|%d|%d|%d|%d|%d|%d|%d|%d|\n", e[id][i / 2][1], e[id][i / 2][2], e[id][i / 2][3], e[id][i / 2][4], e[id][i / 2][5], e[id][i / 2][6], e[id][i / 2][7], e[id][i / 2][8], e[id][i / 2][9]);
	}
}

bool no(int id, int x, int y, int val)
{
	return Row_Exist[id][x][val] || Column_Exist[id][y][val] || Block_Exist[id][findblock(x, y)][val];
}

void fill_num(int id, int x, int y, int val)
{
	e[id][x][y] = val;
	Row_Exist[id][x][val] = 1;
	Column_Exist[id][y][val] = 1;
	Block_Exist[id][findblock(x, y)][val] = 1;
}

void Merge(int id, int id1, int id2)
{
	int cnti = 0, cntj = 0;
//	copy(id);
	for(rgi i = 1; i <= 9; ++i)
		for(rgi j = 1; j <= 9; ++j)
		{
			int cur_val1 = e[id1][i][j];
			int cur_val2 = e[id2][i][j];
			if(no(id, i, j, cur_val1) || cur_val1 == 0)
			{
				if(cur_val2 && no(id, i, j, cur_val2) == 0)
				{
					fill_num(id, i, j, cur_val2);
					cntj++;
				}
			}
			else
			{
				fill_num(id, i, j, cur_val1);
				cnti++;
			}
		}
	printf("%d %d\n", cnti, cntj);
}

int main()
{
//	freopen("sudoku.in", "r", stdin);
//	freopen("sudokuooo.out", "w", stdout);
	In();
	T = read();
	for(rgi i = 1; i <= T; ++i)
	{
		char cmd[10];
		scanf("%s", cmd);
		if(cmd[0] == 'I')//Insert
		{
			int x = read(), y = read(), k = read();
			Insert(i, x, y, k);
		}
		else if(cmd[0] == 'D')//Delete
		{
			int x = read(), y = read();
			Delete(i, x, y);
		}
		else if(cmd[0] == 'Q')//Query
		{
			int x = read(), y = read();
			Query(i, x, y);
		}
		else if(cmd[0] == 'M')//Merge
		{
			int x = read(), y = read();
			Merge(i, x, y);
		}
		else if(cmd[0] == 'P')//Print
			Print(i);
	}
	return 0;
}
