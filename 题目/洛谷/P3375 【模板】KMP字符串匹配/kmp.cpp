#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 1000000 + 10;

char S[N], T[N];
int _next[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Get_Next(char str[])
{
	int len = strlen(str), j, k;
	_next[0] = -1, j = 0, k = -1;
	while(j < len)
	{
		if(k == -1 || str[j] == str[k])
		{
			j++, k++;
			_next[j] = k;
		}
		else
			k = _next[k];
	}
}

void KMP(char T[], char S[])//ÓÃsÆ¥Åät
{
	int lent = strlen(T), lens = strlen(S);
	int i = 0, j = 0;
	while(i < lent && j < lens)
	{
		if(j == -1 || T[i] == S[j])
			i++, j++;
		else
			j = _next[j];
		if(j == lens)
		{
			printf("%d\n", i - j + 1);
			j = _next[j];
		}
	}
}

int main()
{
	scanf("%s", T);
	scanf("%s", S);
	Get_Next(S);
	KMP(T, S);
	int sss = strlen(S);
	for(rgi i = 1; i <= sss; ++i)
		printf("%d ", _next[i]);
	return 0;
}

