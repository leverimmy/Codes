#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int n,a[1000],ans=0;
void init(int a[])
{
	char s[1000];
	int len,i;
	memset(a,0,sizeof(a));
	scanf("%s",s);
	len=strlen(s);
	a[0]=len;
	for(i=1;i<=len;i++)
	{
		if(s[len-i]>='0' && s[len-i]<='9')
			a[i]=s[len-i]-'0';
		else
			a[i]=s[len-i]-'A'+10;
	}
}//读入
void plus(int a[])
{
	int b[1000]; 
	int i,lenc,x;
	int len=a[0];
	for(i=1;i<=len;i++)
		b[i]=a[len-i+1];
	for(i=1;i<=len;i++)
		a[i]+=b[i];
	for(i=1;i<=len;i++)
	{
		a[i+1]+=a[i]/n;
		a[i]%=n;
	}
	if(a[len+1]>0) 
		len++;
	a[0]=len;
}
int huiwen(int a[])
{
	int i;
	int len=a[0];
	for(i=1;i<=len;i++)
		if(a[i]!=a[len-i+1])
			return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	init (a);
	if(huiwen(a)==1)
	{
		printf("0",ans);
		return 0;
	}
	ans=0;
	while(ans++<=30)
	{
		plus(a);
		if(huiwen(a)==1)
		{
		printf("STEP=%d",ans);
		return 0;
		}
	}
	printf("Impossible!");
	return 0;
}