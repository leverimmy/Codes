#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, l = 1, ans = 1, flag;
//flag = 1 -> 上一次是上升
//flag = 0 -> 上一次是下降 
int h[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)	h[i] = read();
	while(h[l] == h[l + 1])	l++;
	if(h[l] < h[l + 1])	flag = 1;
	for(rgi i = l; i <= n - 1; ++i)
	{
		if(flag == 0)	if(h[i] < h[i + 1])	{flag = 1; ans++; continue;}
		if(flag == 1)	if(h[i] > h[i + 1])	{flag = 0; ans++; continue;}
	}
	printf("%d", ans + 1);
	return 0;
}

