#include <cstdio>

using namespace std;

int n,len;
int q[1010]={0,1};

int main()
{
	scanf("%d",&n);
	len=1;
	n++;
	while(n--)
	{
		for(int i=1;i<=len;i++)
		{
			int s=q[i]/2;
			int r=q[i]%2;
			q[i+1]=q[i+1]+r*10;
			q[i]=s;
		}
		len++;
	}
	printf("0.");
	for(int i=2;i<=len-1;i++)
		printf("%d",q[i]);
	return 0;
}