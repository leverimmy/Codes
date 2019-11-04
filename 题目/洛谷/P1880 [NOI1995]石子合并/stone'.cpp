#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 200 + 10;

int n, max_ans = -oo, min_ans = oo;
int a[N], s[N], t[N][N], fmax[N][N], fmin[N][N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Debug_T()
{
	for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= n; ++j)
			cout << t[i][j] << " ";
		cout << endl;
	}
	cout << endl; 
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = a[i + n] = read();
	for(rgi i = 1; i <= n * 2; ++i)
		s[i] = s[i - 1] + a[i];
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = i; j <= i + n; ++j)
			t[i][j] = s[j] - s[i - 1];
	//Debug_T();
	memset(fmin, oo, sizeof(fmin));
	for(rgi i = 1; i <= n + n; ++i)
		fmin[i][i] = 0;
	for(rgi i = n; i >= 1; --i)
		for(rgi j = i + 1; j <= i + n; ++j)
			for(rgi k = i; k <= j - 1; ++k)
			{
				fmax[i][j] = max(fmax[i][j], fmax[i][k] + fmax[k + 1][j] + s[j] - s[i - 1]);
				fmin[i][j] = min(fmin[i][j], fmin[i][k] + fmin[k + 1][j] + s[j] - s[i - 1]); 
			}
	/*for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= n + n; ++j)
			cout << fmax[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= n + n; ++j)
			cout << fmin[i][j] << " ";
		cout << endl;
	}
	cout << endl;*/
	for(rgi i = 1; i <= n; ++i)
	{
		max_ans = max(max_ans, fmax[i][i + n - 1]);
		min_ans = min(min_ans, fmin[i][i + n - 1]);
	}
	printf("%d\n%d", min_ans, max_ans);
	return 0;
}
