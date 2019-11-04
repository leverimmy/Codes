#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cstring>

#define rgi register int
#define il inline
#define ll long long

using namespace std;

int n, cnt;
string s[50];

int main()
{
	//freopen("evolution.in", "r", stdin);
	//freopen("evolution.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		cin.getline(s[++cnt], 50);
		for(int j = 1; j < cnt; j++)
			if(s[cnt].find(s[j], 0) != s[cnt].npos)
			{
				printf("no");
				return 0;
			}
	}
	printf("yes");
	return 0;
}
