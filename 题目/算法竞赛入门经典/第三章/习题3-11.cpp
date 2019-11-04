#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char a[110],b[110];
int lena,lenb,len1,len2;

int match(int i)
{
	int flag=1;
	for(int j=i;j<lenb;j++)
		if(a[j-i]-'0'+b[j]-'0'>3)
		{
			flag=0;
			break;
		}	
	return flag;
}

int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(scanf("%s %s",a,b)==2)
	{
		int flag=0,i;
		lena=strlen(a);
		lenb=strlen(b);
		for(i=0;i<lenb;i++)
			if(match(i))
			{
				flag=1;
				break;
			}
		if(flag)
			len1=max(lena+i,lenb);
		else
			len1=lena+lenb;
		char t[110],s[110];
		strcpy(t,a);
		strcpy(s,b);
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
		strcpy(a,s);
		strcpy(b,t);
		lena=strlen(a);
		lenb=strlen(b);
		flag=0;
		for(i=0;i<lenb;i++)
			if(match(i))
			{
				flag=1;
				break;
			}
		if(flag)
			len2=max(lenb,lena+i);
		else
			len2=lena+lenb;
		printf("%d\n",min(len1,len2));
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
	}
	return 0;
}