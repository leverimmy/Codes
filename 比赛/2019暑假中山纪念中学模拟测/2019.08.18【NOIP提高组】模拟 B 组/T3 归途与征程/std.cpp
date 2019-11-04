#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int N = 100 + 10;
const int M = 100000 + 10;

char A[N], B[M << 1], S[N];
int lena, lenb, tot, ans;
int _next[N], cnt[N], f[N][M << 1];
/*
*	cnt[] -> 每个小段的长度
*	_next[] -> next数组
*	f[i][j] -> 表示第i个小串串在双倍B串中第一次在j位置之后第一次出现的位置
*/
bool flag1, flag2, bz[N][M << 1];
/*
*	flag1 -> B串开头是否是'*'
*	flag2 -> B串末尾是否是'*'
*	bz[i][j] -> 表示第i个小串是否能与B的第j个位置往后相应长度匹配
*/

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void KMP(int start)//从哪一位开始KMP
{
	int j = 0;
	for(rgi i = 2; i <= lena; ++i)
	{
		while(j && S[i] != S[j + 1])
			j = _next[j];
		if(S[i] == S[j + 1])
		{
			j++;
			_next[i] = j;
		}
		else
			_next[i] = j = 0;
	}
	j = 0;
	for(rgi i = 2; i <= lenb << 1; ++i)
	{
		while(j && B[i] != S[j + 1])
			j = _next[j];
		if(B[i] == S[j + 1])
			j++;
		if(j == cnt[start])
			bz[start][i - j + 1] = 1;//能匹配往后一个长度为j的串串 
	}
	f[start][lenb << 1 | 1] = lenb << 1 | 1;
	for(rgi j = lenb << 1; j >= 1; --j)
		if(bz[start][j])
			f[start][j] = j;
		else
			f[start][j] = f[start][j + 1];
}

int Match(int x)//能否塞串串
{
	int y = x + lenb - 1, l = 1, r = tot;
	/*
	*	l -> 小串串中要匹配的第一个 
	*	r -> 小串串中要匹配的最后一个 
	*	y -> 要匹配的末尾位置 
	*/
	if(!flag1)
	{
		if(!bz[l][x])//根本匹配不了 
			return 0;
		x += cnt[l++];//如果第一个不是'*'的话，就要贴脸 
	}
	if(!flag2)
	{
		if(!bz[r][y - cnt[r] + 1])//根本匹配不了 
			return 0;
		y -= cnt[r--];//如果最后一个不是'*'的话，就要贴着屁股 
	}
	for(; l <= r; l++)
	{
		x = f[l][x];
		if(x > y)//长度爆了，匹配不了 
			return 0;
		x += cnt[l] - 1;
	}
	return x > y ? 0 : 1;//长度爆了，匹配不了 
}

int main()
{
	scanf("%s %s", A + 1, B + 1);
	lena = strlen(A + 1), lenb = strlen(B + 1);
	for(rgi i = 1; i <= lenb; ++i)
		B[i + lenb] = B[i];
	flag1 = A[1] == '*';
	flag2 = A[lena] == '*';
	//前后是否为'*'
	for(rgi i = 1; i <= lena; ++i)
	{
		int len = 0;
		for(; i <= lena && A[i] != '*'; ++i)
			S[++len] = A[i];//每个小串串拆出来
		if(!len)//连续的'*'
			continue;
		cnt[++tot] = len;//分成小串串
		KMP(tot);//对每个小串串进行KMP
	}
	for(rgi i = 1; i <= lenb; ++i)
		if(Match(i))//看从每一位开始能否满足“能否将所有小串串塞进从这一位开始的连续的长度为单倍B串的长度的串串”
			ans++;
	printf("%d", ans);
	return 0;
}

