#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

double outRes, stdRes;

int main(int argc, char **argv)  {
  FILE *out = fopen(argv[2], "r");
  FILE *ans = fopen(argv[3], "r");
  FILE *res = fopen(argv[5], "w");

  fscanf(out, "%lf", &outRes);
  fscanf(ans, "%lf", &stdRes);

  if (abs(outRes - stdRes) < 1e-3)
    fprintf(res, "10");
  else
    fprintf(res, "0");

  fclose(out);
  fclose(ans);
  fclose(res);
}
