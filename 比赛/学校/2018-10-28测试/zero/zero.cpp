#include <cstdio>

using namespace std;

int n,flag;
int a1[300],a2[300],a3[300],a4[300],a5[300];

void get()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a1[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a2[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a3[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a4[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a5[i]);
}

int main()
{
	//freopen("zero.in","r",stdin);
	//freopen("zero.out","w",stdout);
	get();
	for(int a=1;a<=n;a++)
		for(int b=1;b<=n;b++)
			for(int c=1;c<=n;c++)
				for(int d=1;d<=n;d++)
					for(int e=1;e<=n;e++)
						if(a1[a]+a2[b]+a3[c]+a4[d]+a5[e]==0)
							flag=1;
	if(flag==1)
		printf("YES");
	else
		printf("NO");
	return 0;
}