#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <queue>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int N = 50 + 10;

int n;
int v[N];

priority_queue <double> pq;

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
	{
		v[i] = read();
		pq.push(-v[i]);
	}
	while(pq.size() > 1)
	{
		double x = pq.top();
		pq.pop();
		double y = pq.top();
		pq.pop();
		pq.push((x + y) / 2.0);
	}
	cout << -pq.top();
	return 0;
}

