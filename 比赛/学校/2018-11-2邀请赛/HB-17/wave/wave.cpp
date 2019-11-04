#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int n,tot;

int main()
{
	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
	scanf("%d",&n);
	srand((unsigned)time(NULL));
	for(int i=1;i<=n;i++)
	{
		int x,y;
		x=y=0;
		scanf("%d %d",&x,&y);
		tot=tot+x+y;
		tot=tot-rand()%n;
	}
	printf("%d",tot);
	return 0;
}