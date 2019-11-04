#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

char ans[550];
int n;
char alphabet[26];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%c",&t);
		alphabet[t-'a']++;
	}
	dfs();
	return 0;
}