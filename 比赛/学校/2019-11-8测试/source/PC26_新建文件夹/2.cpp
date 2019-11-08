#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int _next[MAXN];
char sm[MAXN],lm[MAXN];
void Get_Fail(const int &len)
{
	int i=0,j=-1;
	_next[0]=-1;
	_next[1]=0;
	while(i!=len)
	{
		if(j==-1||sm[i]==sm[j])
		{
			i++;
			j++;
			_next[i]=j;
		}
		else
		{
			j=_next[j];
		}
	}
}
int main()
{
	freopen("2.in","w",stdin);
	freopen("2.out","r",stdout);
	while(scanf("%s",lm)!=EOF)
	{
		memset(_next,0,sizeof(_next));
		bool flag=0;
		scanf("%s",sm);
		int len1=strlen(lm);
		int len2=strlen(sm);
		Get_Fail(len2);
		int i=0,j=0;
		while(i!=len1)
		{
			if(j==-1||lm[i]==sm[j])
			{
				i++;
				j++;
			}
			else
			{
				j=_next[j];
			}
			if(j==len2)
			{
				printf("YES\n");
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			printf("NO\n");
		}
	}
	return 0;
}

