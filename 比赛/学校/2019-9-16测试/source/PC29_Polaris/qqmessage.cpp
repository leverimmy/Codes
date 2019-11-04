#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cctype>
#include<stack>
using namespace std;
const int M=101000;
const int inf=0x3f3f3f3f;
char tar[1100];
int dx[30]={0,1,2,3,5,6,8,9,10,11,13,14,16,17};
struct sentence{
	long long tim;
	char sen[1100],tt[50],name[1100];
}s[1100];
int cnt;
inline int read()
{
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)) {if (s=='-') f=-1; s=getchar();}
	while (isdigit(s)) {x=(x<<1)+(x<<3)+(s^48); s=getchar();}
	return x*f;
}
inline bool cmp(sentence a,sentence b)
{
	return a.tim<b.tim;
}
int main()
{
	freopen("qqmessage.in","r",stdin);
	freopen("qqmessage.out","w",stdout);
	scanf("%s",tar);
	while (scanf("%s",s[++cnt].tt)!=-1)
	{
		bool c=1;
		scanf("%s",s[cnt].tt+10);
		scanf("%s",s[cnt].name);
		gets(s[cnt].sen);
		for (int i=0;i<strlen(tar);i++)
		{
			if (s[cnt].name[i]!=tar[i])
			{
				cnt--;
				c=0;
				break;
			}
		}
		if (!c) continue;
		for (int i=0;i<=13;i++)
		{
			s[cnt].tim=(s[cnt].tim<<1)+(s[cnt].tim<<3)+(s[cnt].tt[dx[i]]^48);
		}
	}
	cnt--;
	sort(s+1,s+cnt+1,cmp);
	for (int i=1;i<=cnt;i++)
	{
		for (int j=1;j<strlen(s[i].sen);j++)
		{
			printf("%c",s[i].sen[j]);
		}
		printf("\n");
	}
	return 0;
}
