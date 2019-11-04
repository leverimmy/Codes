#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int N = 100 + 10;

int n, a[N];

double up = 1.0, down;

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	for(rgi i = 1; i <= n; ++i)
		up *= a[i];
	for(rgi i = 1; i <= n; ++i)
		down += up / a[i];
//	cout << up << " " << down << endl;
	printf("%.4lf", up / down);
	return 0;
}

