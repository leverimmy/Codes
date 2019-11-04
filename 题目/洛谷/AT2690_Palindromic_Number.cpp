#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	if(n/100==n%10)//n/100是百位；n%10是个位
		printf("Yes");
	else
		printf("No");
	return 0;
}