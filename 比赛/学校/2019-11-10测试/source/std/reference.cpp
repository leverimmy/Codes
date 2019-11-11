#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

char s[10010];
int n, cnt;

int main()  {
    freopen("reference.in","r",stdin);  freopen("reference.out","w",stdout); 
  scanf("%d", &n);
  scanf("%s", s + 1);
  
  int x = 0, y = n + 1;
  while (++x < --y)  {
    if (s[x] == s[y])
      continue;
    int nx = x + 1, ny = y - 1;
    while (s[nx] != s[y])
      ++nx;
    while (s[ny] != s[x])
      --ny;
    if (nx == y  &&  ny == x)  {
      printf("Impossible");
      return 0;
    }
    if (nx - x <= y - ny  &&  nx != y)
      for (int i = nx; i > x; --i)
	swap(s[i], s[i - 1]), ++cnt;
    else
      for (int i = ny; i < y; ++i)
	swap(s[i], s[i + 1]), ++cnt;
  }
  printf("%d\n", cnt);
}
