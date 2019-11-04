#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 110
#define maxl 10010

using namespace std;

int n, l, flag, cnt;
int t[maxn], A[maxl], B[maxl];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

void check(int A[], int pos, int end)
{
	while(pos < end)
	{
		if(A[pos] != A[end])
		{
			flag = 0;
			return;
		}
		else
			pos++, end--;
	}
}

int main()
{
	n = read(), l = read();				
	for(rgi i = 1; i <= n; ++i)
	{
		t[i] = read();
		A[t[i]] = 1;
	}
	for(rgi i = 1; i <= n; ++i)
	{
		flag = 1;
		check(A, t[i], l);
		if(flag)
			cnt++;
		//printf("::%d\n::", (t[i] + l) >> 1);
		flag = 1;
		check(A, 0, t[i]);
		if(flag)
			cnt++;
		//printf("::%d\n::", (0 + t[i]) >> 1);
	}
	write(cnt - 2);
	return 0;
}

