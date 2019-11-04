#include <cstdio>
#include <algorithm>

using namespace std;

int n,r,q;

struct people
{
	int id,score,weight;
}a[100010];

bool cmp(struct people a,struct people b)
{
	if(a.score==b.score)
		return a.id<b.id;
	else
		return a.score>b.score;
}

void init()
{
	for(int i=1;i<=n;i++)
		a[i].id=i;
}

int main()
{
	scanf("%d %d %d",&n,&r,&q);
	init();
	for(int i=1;i<=2*n;i++)
		scanf("%d",&a[i].score);
	for(int i=1;i<=2*n;i++)
		scanf("%d",&a[i].weight);
	while(r--)
	{
		sort(a+1,a+n*2+1,cmp);
		for(int i=1;i<=2*n-1;i+=2)
		{
			if(a[i].weight>a[i+1].weight)
			{
				a[i].score++;
			}
			else if(a[i+1].weight>a[i].weight)
			{
				a[i+1].score++;
			}
		}
	}
	printf("%d",a[q].id);
	return 0;
}