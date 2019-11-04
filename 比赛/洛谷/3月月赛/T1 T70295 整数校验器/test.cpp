#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
#define ll long long
#define ull unsigned long long

using namespace std;

int T;
ll l, r;

int main()
{
	cin >> l >> r >> T;
	getchar();
	for(int i = 1; i <= T; i++)
	{
		int flag = 0, len = 0;
		int flag_neg = 0;
		int flag_zero = 0;
		ll cur = 0;
		char ch;
		while(ch = getchar())
		{
			++len;
			if(flag == 1)
			{
				if(ch == '\n')
					break;
				else
					continue;
			}
			if(flag_neg && len == 2 && ch == '0')
			{
				printf("1\n");
				flag = 1;
				continue;
			}
			if(flag_zero)
			{
				if(ch == '\n')
				{
					printf("0\n");
					break;
				}
				printf("1\n");
				flag = 1;
				continue;
			}
			if(ch == '\n')
			{
				if(flag_neg)
				{
					if(cur - l < 0 || cur - r > 0)
					{
						printf("2\n");
						break;
					}
				}
				else if(!flag_neg)
				{
					if(cur < l || cur > r)
					{
						printf("2\n");
						break;
					}
				}
				printf("0\n");
				break;
			}
			if(ch == '0' && len == 1)
			{
				flag_zero = 1;
				continue;
			}
			if(ch == '-' && len == 1)
			{
				flag_neg = 1;
				continue;
			}
			cur *= 10;
			cur += ch - '0';
		}
	}
	return 0;
}
