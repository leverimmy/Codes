#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#define maxn 10000

using namespace std;

int p, q, r, s;
int ex[maxn + 5];
int vis[maxn + 5];
vector <int> primes;

void make_table()
{
	for(int i = 2; i <= 100; i++)
		if(vis[i] != 1)
			for(int j = i * i; j <= 10000; j += i)
				vis[j] = 1;
	for(int i = 2; i <= 10000; i++)
		if(!vis[i])
			primes.push_back(i);
}

void add_int(int num, int op)
{
	for(int i = 0; i < primes.size(); i++)
	{
		while(num % primes[i] == 0)
		{
			num /= primes[i];
			ex[i] += op;
		}
		if(num == 1)
			break;
	}
}

void add_factorial(int num, int op)
{
	for(int i = 1; i <= num; i++)
		add_int(i, op);
}

int main()
{
	make_table();
	while(cin >> p >> q >> r >> s)
	{
		memset(ex, 0, sizeof(ex));
		add_factorial(p, 1);
		add_factorial(q, -1);
		add_factorial(p - q, -1);
		add_factorial(r, -1);
		add_factorial(s, 1);
		add_factorial(r - s, 1);
		double ans = 1.0;
		for(int i = 0; i < primes.size(); i++)
			ans *= pow(primes[i]*1.0, ex[i]);
		printf("%.5f\n", ans);
	}
	return 0;
}

