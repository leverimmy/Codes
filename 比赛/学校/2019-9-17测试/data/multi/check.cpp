#include <map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

map <int, double> Edge[100010];
int n, m, x, y, z;
int start, end;

double calcRouteScore(FILE *log)  {
  int last, now;
  double res = 0;
  fscanf(log, "%d", &last);
  if (last != start)
    return -1;
  while (fscanf(log, "%d", &now) != EOF)  {
    if (Edge[last].find(now) == Edge[last].end())
      return -1;
    res += Edge[last][now];
    last = now;
  }
  if (last != end)
    return -1;
  return res;
}
int main(int argc, char **argv)  {
  FILE *in  = fopen(argv[1], "r");
  FILE *out = fopen(argv[2], "r");
  FILE *std = fopen(argv[3], "r");
  FILE *res = fopen(argv[5], "w");
  FILE* freport = fopen(argv[6], "w");

  fscanf(in, "%d %d", &n, &m);
  for (int i = 1; i <= m; ++i)  {
    fscanf(in, "%d %d %d", &x, &y, &z);
    if (!Edge[x].count(y)) Edge[x][y] = log(z);
    else Edge[x][y] = min(Edge[x][y], log(z));
    if (!Edge[y].count(x)) Edge[y][x] = log(z);
    else Edge[y][x] = min(Edge[y][x], log(z));
  }

 fscanf(in, "%d %d\n", &start, &end);

  double stdRes = calcRouteScore(std);
  double outRes = calcRouteScore(out);
  
  fprintf(freport, "%.10lf %.10lf", outRes, stdRes);
  if (outRes - stdRes < 1e-5)
    fprintf(res, "10");
  else
    fprintf(res, "0");
  fclose(in);
  fclose(out);
  fclose(std);
  fclose(res);
}
