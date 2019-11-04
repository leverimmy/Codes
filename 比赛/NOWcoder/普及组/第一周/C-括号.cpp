#include <cstdio>
#include <algorithm>
#include <cstring>
#define MOD 1000000007

using namespace std;

int n;
char s[10010];
int f[10010]={1,0};

int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<=strlen(s)-1;i++)
	{
		if(s[i]=='(')
			for(int j=n-i;j>=0;j--)
				f[j+1]=(f[j+1]+f[j])%MOD;
		else
            for(int j=1;j<=n-i;j++)
				f[j-1]=(f[j-1]+f[j])%MOD;
	}
	printf("%d",(f[0]-1+MOD)%MOD);
	return 0;
}