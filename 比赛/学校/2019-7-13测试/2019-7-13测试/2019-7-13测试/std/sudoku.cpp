#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

int read()
{
	int out = 0;
	char c;
	for (c = getchar(); !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar())
	{
		out = out * 10 + c - '0';
	}
	return out;
}

const int BL[10][10] =
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
	{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
	{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
	{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
	{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
	{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
	{0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
	{0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
	{0, 7, 7, 7, 8, 8, 8, 9, 9, 9}
};

int t, a[110][10][10], ans, fromx, fromy;
bool row[10][10], col[10][10], squ[10][10];
char op[20];

int main()
{
	freopen("sudoku.in", "r", stdin);
	freopen("sudoku.out", "w", stdout);
	int q, i, j, x, y, k;
	for (i = 1; i <= 9; ++i)
	{
		for (j = 1; j <= 9; ++j)
		{
			a[0][i][j] = k = read();
			if (k)
			{
				row[i][k] = col[j][k] = squ[BL[i][j]][k] = true;
			}
		}
	}
	t = read();
	for (q = 1; q <= t; ++q)
	{
		scanf("%s", op);
		switch (op[0])
		{
			case 'I':
				x = read();
				y = read();
				k = read();
				for (i = 1; i <= 9; ++i)
				{
					for (j = 1; j <= 9; ++j)
					{
						a[q][i][j] = a[q - 1][i][j];
					}
				}
				if (a[q][x][y])
				{
					puts("Error!");
				}
				else if (row[x][k])
				{
					puts("Error:row!");
				}
				else if (col[y][k])
				{
					puts("Error:column!");
				}
				else if (squ[BL[x][y]][k])
				{
					puts("Error:square!");
				}
				else
				{
					puts("OK!");
					a[q][x][y] = k;
					row[x][k] = col[y][k] = squ[BL[x][y]][k] = true;
				}
				break;
			case 'D':
				x = read();
				y = read();
				for (i = 1; i <= 9; ++i)
				{
					for (j = 1; j <= 9; ++j)
					{
						a[q][i][j] = a[q - 1][i][j];
					}
				}
				k = a[q][x][y];
				if (k)
				{
					puts("OK!");
					a[q][x][y] = 0;
					row[x][k] = col[y][k] = squ[BL[x][y]][k] = false;
				}
				else
				{
					puts("Error!");
				}
				break;
			case 'Q':
				x = read();
				y = read();
				for (i = 1; i <= 9; ++i)
				{
					for (j = 1; j <= 9; ++j)
					{
						a[q][i][j] = a[q - 1][i][j];
					}
				}
				if (a[q][x][y])
				{
					puts("Error!");
				}
				else
				{
					ans = 0;
					for (k = 1; k <= 9; ++k)
					{
						if (!row[x][k] && !col[y][k] && !squ[BL[x][y]][k])
						{
							++ans;
						}
					}
					printf("%d\n", ans);
					for (k = 1; k <= 9; ++k)
					{
						if (!row[x][k] && !col[y][k] && !squ[BL[x][y]][k])
						{
							printf("%d\n", k);
						}
					}
				}
				break;
			case 'M':
				x = read();
				y = read();
				fromx = fromy = 0;
				memset(row, false, sizeof(row));
				memset(col, false, sizeof(col));
				memset(squ, false, sizeof(squ));
				for (i = 1; i <= 9; ++i)
				{
					for (j = 1; j <= 9; ++j)
					{
						k = a[x][i][j];
						if (k && !row[i][k] && !col[j][k] && !squ[BL[i][j]][k])
						{
							a[q][i][j] = k;
							row[i][k] = col[j][k] = squ[BL[i][j]][k] = true;
							++fromx;
						}
						else
						{
							k = a[y][i][j];
							if (k && !row[i][k] && !col[j][k] && !squ[BL[i][j]][k])
							{
								a[q][i][j] = k;
								row[i][k] = col[j][k] = squ[BL[i][j]][k] = true;
								++fromy;
							}
						}
					}
				}
				printf("%d %d\n", fromx, fromy);
				break;
			case 'P':
				for (i = 1; i <= 9; ++i)
				{
					for (j = 1; j <= 9; ++j)
					{
						a[q][i][j] = a[q - 1][i][j];
					}
				}
				for (i = 1; i <= 9; ++i)
				{
					puts("+-+-+-+-+-+-+-+-+-+");
					for (j = 1; j <= 9; ++j)
					{
						printf("|%d", a[q][i][j]);
					}
					puts("|");
				}
				puts("+-+-+-+-+-+-+-+-+-+");
				break;
		}
	}
	return 0;
}
