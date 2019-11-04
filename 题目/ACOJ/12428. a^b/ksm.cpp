#include <iostream>

using namespace std;

long long a, b, p, res;

int main()
{
	cin >> a >> b >> p;
	res = 1 % p;
	while(b)
	{
		if(b & 1)
			res = res * a % p;
	   a = a * a % p;
		b >>= 1;
	}
	cout << res;
	return 0;
}
