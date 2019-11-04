#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define MOD 239

using namespace std;

int random(int l, int r)
{
	return rand() * rand() % (r - l) + l;
}

int main()
{
	srand((unsigned)time(0));
	printf("%d", random(100, 200));
	return 0;
}

