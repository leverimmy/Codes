#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 10010

using namespace std;

int p1, p2, p3, len;
char flag, str[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Reverse(char cur[], int cur_len)
{
	char temp[maxn] = {'\0'};
	for(rgi i = 0; i < cur_len; ++i)
		temp[i] = cur[cur_len - i - 1];
	for(rgi i = 0; i < cur_len; ++i)
		cur[i] = temp[i];
}

void Insert(char from[], int len_from, char to[], int pos)
{
	char temp[maxn] = {'\0'};
	for(rgi i = pos + 1; i < len; ++i)
		temp[i - (pos + 1)] = to[i];
	for(rgi i = 0; i < len_from; ++i)
		to[pos + i] = from[i];
	for(rgi i = len_from + pos; i < len_from + len - 1; ++i)
		to[i] = temp[i - (len_from + pos)];
	len = len_from + len - 1;
	for(rgi i = len; i < maxn; ++i)
		to[i] = '\0';
}

int main()
{
	p1 = read(), p2 = read(), p3 = read();
	scanf("%s", str);
	len = strlen(str);
	flag = str[0];
	if(p1 == 1)//lower
	{
		for(rgi i = 0; i < len; ++i)
		{
			if(str[i] == '-')
			{
				if(!i || str[i - 1] >= str[i + 1] || (isalpha(str[i - 1]) && !isalpha(str[i + 1])) || (!isalpha(str[i - 1]) && isalpha(str[i + 1])) || (isdigit(str[i - 1] && !isdigit(str[i + 1]))) || (!isdigit(str[i - 1]) && isdigit(str[i + 1])))
					continue;
				else
				{
					char in[maxn] = {'\0'};
					int siz = 0;
					for(register char ch = str[i - 1] + 1; ch <= str[i + 1] - 1; ++ch)
						for(rgi j = 1; j <= p2; ++j)
							in[siz++] = ch;
					if(isalpha(str[i + 1]) && isalpha(str[i - 1]))
						for(rgi j = 0; j < siz; ++j)
							in[j] = tolower(in[j]);
//					puts(in);
					if(p3 == 2)
						Reverse(in, siz);
					Insert(in, siz, str, i);
				}
			}
		}
	}
	else if(p1 == 2)//upper
	{
		for(rgi i = 0; i < len; ++i)
		{
			if(str[i] == '-')
			{
				if(!i || str[i - 1] >= str[i + 1] || (isalpha(str[i - 1]) && !isalpha(str[i + 1])) || (!isalpha(str[i - 1]) && isalpha(str[i + 1])) || (isdigit(str[i - 1] && !isdigit(str[i + 1]))) || (!isdigit(str[i - 1]) && isdigit(str[i + 1])))
					continue;
				else
				{
					char in[maxn] = {'\0'};
					int siz = 0;
					for(register char ch = str[i - 1] + 1; ch <= str[i + 1] - 1; ++ch)
						for(rgi j = 1; j <= p2; ++j)
							in[siz++] = ch;
					if(isalpha(str[i + 1]) && isalpha(str[i - 1]))
						for(rgi j = 0; j < siz; ++j)
							in[j] = toupper(in[j]);
					if(p3 == 2)
						Reverse(in, siz);
					Insert(in, siz, str, i);
				}
			}
		}
	}
	else if(p1 == 3)//'*'
	{
		for(rgi i = 0; i < len; ++i)
		{
			if(str[i] == '-')
			{
				if(!i || str[i - 1] >= str[i + 1] || (isalpha(str[i - 1]) && !isalpha(str[i + 1])) || (!isalpha(str[i - 1]) && isalpha(str[i + 1])) || (isdigit(str[i - 1] && !isdigit(str[i + 1]))) || (!isdigit(str[i - 1]) && isdigit(str[i + 1])))
					continue;
				else
				{
					char in[maxn] = {'\0'};
					int siz = 0;
					for(register char ch = str[i - 1] + 1; ch <= str[i + 1] - 1; ++ch)
						for(rgi j = 1; j <= p2; ++j)
							in[siz++] = ch;
					for(rgi j = 0; j < siz; ++j)
						in[j] = '*';
					Insert(in, siz, str, i);
				}
			}
		}
	}
	printf("%s", str);
	return 0;
}

