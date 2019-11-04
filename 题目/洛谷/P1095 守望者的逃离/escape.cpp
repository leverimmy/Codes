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

int m, s, t;
int s1, s2, flag;
//s1 -> 截至当前时刻，跑步能达到的最长距离
//s2 -> 截至当前时刻，闪烁能达到的最长距离 

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	m = read(), s = read(), t = read();
	for(rgi i = 1; i <= t; ++i)
	{
		s1 += 17;
		//处理跑步 
		if(m >= 10)
		{
			s2 += 60;
			m -= 10;
		}
		else 
			m += 4;
		//处理闪烁
		 
		if(s2 > s1) 
			s1 = s2;
		if(s1 > s)
		{
			flag = i;
			break;
		}
	}
	if(flag)
		printf("Yes\n%d", flag);
	else
		printf("No\n%d", s1);
	return 0;
}

