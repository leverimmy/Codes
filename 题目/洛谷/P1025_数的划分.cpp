#include <cstdio>

using namespace std;

int n,k,ans;

void dfs(int cur,int step,int left)
{
	if(step==k && left==0)
	{
		ans++;
		return;
	}
	if(step!=k && left!=0)
	{
		for(int i=cur;i<=left;i++)
		{
			dfs(i,step+1,left-i);
		}
	}
}

int main()
{
	scanf("%d %d",&n,&k);
	dfs(1,0,n);
	printf("%d",ans);
	return 0;
}