#include <cstdio>
#include <iostream>
#include <cstring>
#define ll long long
#define ull unsigned long long

using namespace std;

ull a, b;
int T, mod, len, r;
int f[1000100] = {0, 1, 1};

ull ksm(ull base, ull power, ull m)
{
	ull ans = 1;
	while(power)
	{
		if(power & 1)
			ans = ans * base % m;
		base = base * base % m;
		power >>= 1;
	}
	return ans % m;
}

int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> a >> b >> mod;
		if(a == 0 || mod == 1)
		{
			printf("0\n");
			continue;
		}
		f[1] = f[2] = 1;
		for(int i = 3; i <= mod * mod + 5; i++)
		{
			f[i] = (f[i - 1] + f[i - 2]) % mod;
			if(f[i] == f[2] && f[i - 1] == f[1])
			{
				len = i - 2;
				break;
			}
		}
		r = ksm(a % len, b, len);
		cout << f[r] << "\n";
	}
	return 0;
}

