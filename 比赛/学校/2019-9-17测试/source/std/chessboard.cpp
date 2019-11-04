#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

typedef int Arr32[110];

Arr32 edge[110], vis, lef;
char col[110];
int n, cnt, mark;

bool find(int z)  {
  for (int i = 1; i <= n; ++i)
    if (edge[z][i] == true)  {
      if (vis[i] == mark)  continue;
      vis[i] = mark;
      if (lef[i] == 0  ||  find(lef[i]))  {
	lef[i] = z;
	return true;
      }
    }
  return false;
}
int main()  {
  freopen("chessboard.in", "r", stdin);
  freopen("chessboard.out", "w", stdout);

  cin >> n;
  for (int i = 1; i <= n; ++i)  {
    scanf("%s", col + 1);
    for (int j = 1; j <= n; ++j)
      edge[i][j] = col[j] == '.';
  }
  for (int i = 1; i <= n; ++i)  {
    ++mark;
    cnt += find(i);
  }
  cout << cnt << endl;
}
