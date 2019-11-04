#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n,l,k,len;
char s[110];
int count[9];

int main()
{
	scanf("%d %d %d",&n,&l,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<=strlen(s)-1;j++)
			count[s[i]-'a'+1]++;
	}
	for()
	return 0;
}