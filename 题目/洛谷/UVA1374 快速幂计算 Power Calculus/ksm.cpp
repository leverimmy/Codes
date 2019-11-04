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

int n;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	while(cin >> n)
	{
		if(!n)
			break;
		int cnt = 0;
		while(n)
		{
			n >>= 1;
			cnt++;
		}
		cout << "ans : " << cnt << endl;
	}
	return 0;
}
/*
1
31
70
91
473
512
811
953
0

*/

