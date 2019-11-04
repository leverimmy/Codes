#include <cstdio>
#include <cstring>

using namespace std;

int T;
char s[110<<1];

int smaller(int i,int j)
{
	int len=strlen(s);
	for(int k=0;k<len;k++)
	{
		if(s[(i+k)%len] > s[(j+k)%len])
			return 0;
		else if(s[(i+k)%len] < s[(j+k)%len])
			return 1;
		else	if(s[(i+k)%len] == s[(j+k)%len])
			continue;
	}
	return 0;
}


int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int len,ans=0;
		scanf("%s",s);
		len=strlen(s);
		for(int i=0;i<len;i++)
			s[len+i]=s[i];
		for(int i=0;i<len;i++)
		{
			if(smaller(i,ans)==1)
				ans=i;
		}
		for(int i=ans;i<ans+len;i++)
			printf("%c",s[i]);
		memset(s,'\0',sizeof(s));
		printf("\n");
	}
	return 0;
}