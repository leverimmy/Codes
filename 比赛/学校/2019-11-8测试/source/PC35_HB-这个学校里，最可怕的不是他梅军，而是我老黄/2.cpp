#include<cstdio>
#include<cstring>
#include<climits>
#include<cassert>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
void get_next(char *s1,int *next,int len1)
{
	int i=0,j=-1;
	next[i]=j;
	while(i<=len1-1)
	{
		if(j==-1||s1[i]==s1[j])
		{
			i++;
			j++;
			next[i]=j;
		}
		else
			j=next[j];
	}
}
bool index_KMP(char *s1,char *s2,int *next,int len1,int len2)
{
	int i=0,j=0;
	while(i<=len1-1)
	{
		if(j==-1||s1[i]==s2[j])
		{
			i++;
			j++;
		}
		else
			j=next[j];
		if(j==len2)
			return 1;
	}
	return 0;
}
int next[100010];
char s1[100010];
char s2[100010];
signed main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	while(~scanf("%s%s",s1,s2))
	{
		memset(next,0,sizeof(next));
		int len1(strlen(s1));
		int len2(strlen(s2));
		get_next(s2,next,len2);
		if(index_KMP(s1,s2,next,len1,len2))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

