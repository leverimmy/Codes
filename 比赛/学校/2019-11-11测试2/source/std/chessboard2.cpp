#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int sum[2][1<<11][1<<11], ans[1001][1001], op[100001][6];
int list[30], n, l1, r1, l2, r2, x, y, flag, c, tot;


void Split_On_Y(int i, int l, int r)     //1：找到y上对应的区间，用于快速判断是否全部被染色
{
    if (l2 <= l && r <= r2)
		{
			list[++ tot] = i;
			return;
		}
    int mid = l + r >> 1;
    if (l2 < mid) Split_On_Y(i * 2, l, mid);
    if (r2 > mid) Split_On_Y(i * 2 + 1, mid, r);
}

void Cover(int x, int y)  //染色，对于不需要染的我们也sum++，这样下一次仍不需要染时不会再进来
{
    for (int i = x; i; i >>= 1)
		for (int j = y; j; j >>= 1)
			sum[flag][i][j] ++;
}

int Get_Sum_On_Y(int sum[])
{
    int res = 0, i;
    for (i = 1; i <= tot; i ++) res += sum[list[i]];
    return res;
}

void Find_On_Y(int sum[], int i, int l, int r, int loc) //5：一维情况，对于确定x，确定的y的区间，找到区间内需要染色的点
{
    if (l + 1 == r)
		{
			Cover(loc, i);
			if ((x + r) % 2 == flag) ans[x][r] = c;  //判断是否需要染
			return;
		}
    int mid = l + r >> 1;
    if (sum[i*2] < mid - l)
		Find_On_Y(sum, i * 2, l, mid, loc);
    if (sum[i*2+1] < r - mid)
		Find_On_Y(sum, i * 2 + 1, mid, r, loc);
}

void Check_On_Y(int sum[], int i, int l, int r, int loc)  //4：变为一维情况，对于确定x，找到需要染色的y的区间，进去染色
{
    if (l2 <= l && r <= r2)
		{
			if (sum[i] < r - l) Find_On_Y(sum, i, l, r, loc);
			return;
		}
    int mid = l + r >> 1;
    if (l2 < mid) Check_On_Y(sum, i * 2, l, mid, loc);
    if (r2 > mid) Check_On_Y(sum, i * 2 + 1, mid, r, loc);
}

void Find_On_X(int i, int l, int r)  //3：找到需要染色的x位置（注意是位置而不是区间），进去染色
{
    if (l + 1 == r)
		{
			x = r, Check_On_Y(sum[flag][i], 1, 0, n, i);
			return;
		}
    int mid = l + r >> 1;
    if (Get_Sum_On_Y(sum[flag][i*2]) < (mid - l) * (r2 - l2))
		Find_On_X(i * 2, l, mid);
    if (Get_Sum_On_Y(sum[flag][i*2+1]) < (r - mid) * (r2 - l2))
		Find_On_X(i * 2 + 1, mid, r);
}

bool Check_On_X(int i, int l, int r)  //2：先划分x坐标，再划分y坐标
{
    if (l1 <= l && r <= r1)
		{
			int tmp = Get_Sum_On_Y(sum[flag][i]);
			if (tmp < (r - l) * (r2 - l2))  //如果对应x坐标区间，对应y坐标，没有染满，进去染色
				{
					Find_On_X(i, l, r);
					return true;
				}
			else
				return false;
		}
    int mid = l + r >> 1;
    bool res = false;
    if (l1 < mid) res = res || Check_On_X(i * 2, l, mid);
    if (r1 > mid) res = res || Check_On_X(i * 2 + 1, mid, r);
    return res;
}

int main()
{
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
    int k, m, i, j, now;
    char ctrl[20];
    
    scanf("%d%d%d", &n, &k, &m);
    for (now = 0, i = 1; i <= m; i ++)
		{
			scanf("%s", ctrl);
			if (ctrl[0] == 'P')
				{
					op[i][0] = 1, scanf("%d", &op[i][1]);
					scanf("%d%d", &op[i][2], &op[i][3]);
					scanf("%d%d", &op[i][4], &op[i][5]);
				}
			if (ctrl[0] == 'S')
				op[i][0] = 2, op[i][1] = ++ now;
			if (ctrl[0] == 'L')
				op[i][0] = 3, scanf("%d", &op[i][1]);
		}
    
    for (i = 1; i <= n; i ++)
		for (j = 1; j <= n; j ++)
			ans[i][j] = 1;
    memset(sum, 0, sizeof(sum));
    for (i = m; i; i --)
		{
			if (op[i][0] == 1)
				{
					flag = (op[i][2] + op[i][3]) % 2, c = op[i][1];
					l1 = op[i][2], r1 = op[i][4] + 1;
					l2 = op[i][3], r2 = op[i][5] + 1;
					tot = 0, Split_On_Y(1, 0, n);
					for ( ; Check_On_X(1, 0, n); );
				}
			if (op[i][0] == 3)
				for (now = op[i][1]; ; i --)
					if (op[i][0] == 2 && op[i][1] == now) break;
		}
    
    for (i = 1; i <= n; i ++)
		for (j = 1; j <= n; j ++)
			printf("%d%c", ans[i][j], (j < n) ? ' ' : '\n');
    
    return 0;
}
