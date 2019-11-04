#include <cstdio>

using namespace std;

int n,m,cnt;
int h[200010];

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if((h[i]-h[j]==j-i)||(h[j]-h[i]==j-i)||(h[i]+h[j]==j-i))
				cnt++;
		}
	printf("%d",cnt);
	return 0;
}