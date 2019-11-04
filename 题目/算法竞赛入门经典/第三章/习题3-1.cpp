#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[90];
int len,score,sum,q;

int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",s);
		len=strlen(s);
		for(int i=0;i<=len-1;i++)
		{
			if(s[i]=='X')
				sum=0;
			else if(s[i]=='O')
			{
				sum++;
				score+=sum;
			}
		}
		printf("%d",score);
		len=score=sum=0;
	}
	return 0;
}