#include <cstdio>
#include <cstring>

using namespace std;

int k,len;
char num[1010];

int main()
{
	scanf("%d %s",&k,num);
	len=strlen(num);
	for(int i=0;i<len;i++)
	{
		if(i!=0 && num[i]-'0'!=0)
			printf("+");
		if(num[i]-'0'!=0)
			printf("%d*%d^%d",num[i]-'0',k,len-i-1);
	}
	return 0;
}