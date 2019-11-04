#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register long long
#define il inline
#define ll long long

using namespace std;

ll T;
ll fib[50] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903};

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool check(ll x)
{
	ll cur = 46, res = x, cnt = 3;
	while(cur && cnt)
	{
		if(res >= fib[cur])
		{
			res -= fib[cur];
			cnt--;
		}
		cur--;
	}
	return !res;
}

int main()
{
	T = read();
	while(T--)
	{
		ll n = read();
		if(check(n))
			puts("MINAMI");
		else
			puts("KOTORI");
	}
	return 0;
}

