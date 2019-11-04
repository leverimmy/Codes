#include <cstdio>
#include <cstdlib>
using namespace std;
struct node
{
	int l,r,cnt;
} tree[400005];
int n,m,a[100005],l[100005],r[100005],v[100005],p[100005]; 
int main()
{
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bool flag=true;
	scanf("%d%d%d%d",&l[0],&r[0],&p[0],&v[0]);
	for(int i=1;i<m;i++)
	{
		scanf("%d%d%d%d",&l[i],&r[i],&p[i],&v[i]);
		if(p[i]!=p[0]) flag=false;
		v[i]%=p[i];
	}
	for(int i=0;i<m;i++)
	{
		int cnt=0;
		for(int j=l[i];j<=r[i];j++)
		{
			if(a[j]%p[i]==v[i]) cnt++;
		}
		printf("%d\n",cnt);
	}
	//system("pause");
	return 0;
}
