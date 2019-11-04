#include <cstdio>

using namespace std;

int n,q,tx,ty;
char map[2020][2020];

int countx(int a,int b)
{
	int l,r,ans=1;
	l=a-1;r=a+1;
	while(map[l][b]==map[r][b])
	{
		if(l==0 || r==n+1)
			break;
		l--;r++;
		ans+=2;
	}
	return ans;
}

int county(int a,int b)
{
	int l,r,ans=1;
	l=b-1;r=b+1;
	while(map[a][l]==map[a][r])
	{
		if(l==0 || r==n+1)
			break;
		l--;r++;
		ans+=2;
	}
	return ans;
}

int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%s",map[i]);
	for(int j=1;j<=n;j++)
		for(int i=n-1;i>=0;i--)
			map[j][i+1]=map[j][i];
	while(q--)
	{
		scanf("%d %d",&tx,&ty);
		int num1=countx(tx,ty);
		int num2=county(tx,ty);
		int num=num1>num2?num1:num2;
		printf("%d\n",num);
	}
	return 0;
}