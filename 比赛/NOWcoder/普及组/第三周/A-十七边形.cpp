#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const double sinalpha=0.36124166618715294874394872745022;
int r;

int main()
{
	scanf("%d",&r);
	printf("%.6f",17*sinalpha*r*r/2);
	return 0;
}