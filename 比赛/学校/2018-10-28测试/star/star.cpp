#include <cstdio>

using namespace std;

int n,k,min=99999;
int map[500][500];

int count(int startx,int starty,int endx,int endy)
{
	int ans=0;
	for(int i=startx;i<=endx;i++)
		for(int j=starty;j<=endy;j++)
			ans+=map[i][j];
	return ans;
}

int sur(int a,int b,int c,int d)
{
	return (b-a+1)*(d-c+1);
}

int main()
{
	//freopen("star.in","r",stdin);
	//freopen("star.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		map[x][y]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			for(int k=1;k<=n;k++)
				for(int t=k;t<=n;t++)
					if(count(i,j,k,t)>=k && sur(i,j,k,t)<min)
						min=sur(i,j,k,t);
	printf("%d",min);
	return 0;
}