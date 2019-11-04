#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <iostream>

using namespace std;

bool cmp(string a,string b)
{
	return a+b>b+a;
}

string a[110];
int n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		printf("%s",a[i].c_str());
	return 0;
}

