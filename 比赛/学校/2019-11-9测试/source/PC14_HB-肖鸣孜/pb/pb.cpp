#include <cstdio>
#include <algorithm>
using namespace std;
int n,w,u[105];
double usum,p[105];
int main()
{
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	scanf("%d%d",&n,&w);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&u[i]);	
		usum+=u[i];
	}
	for(int i=0;i<n;i++) p[i]=1.0*u[i]/usum;
	sort(p,p+n);
	return 0;
}
