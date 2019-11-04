#include <cstdio>

using namespace std;

int n,flag=1;
char x[110],y[110],z[110];

int main()
{
	scanf("%d",&n);
	scanf("%s",x);
	scanf("%s",y);
	for(int i=0;i<n;i++)
	{
		if(x[i]<y[i])
		{
			printf("-1");
			flag=0;
			break;
		}
	}
	if(flag)
		puts(y);
	return 0;
}