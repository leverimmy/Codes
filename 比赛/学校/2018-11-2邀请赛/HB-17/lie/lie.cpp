#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int n,tot;

int main()
{
	freopen("lie.in","r",stdin);
	freopen("lie.out","w",stdout);
	srand((unsigned)time(NULL));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		tot++;
		tot=tot-rand()%n;
	}
	printf("%d",tot);
	return 0;
}