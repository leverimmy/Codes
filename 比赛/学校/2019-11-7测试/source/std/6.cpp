#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;
string s[30];
int n;

int main()
{
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
	scanf("%d",&n);
	s[1] = 'A';
	for (int i = 2; i <= n; i++)
	{
		char ch = 'A' + i - 1;
		s[i] = s[i - 1] + ch + s[i - 1];
	}
	cout << s[n] << endl;
	
	return 0;
}
