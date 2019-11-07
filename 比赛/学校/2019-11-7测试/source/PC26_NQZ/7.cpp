#include <bits/stdc++.h>
using namespace std;
int _map[30][30];
int book[30];
int main()
{
	freopen("7.in","r",stdin);
	freopen("7.out","w",stdout);
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf("%d",&_map[i][j]);
			if(i==j)
			{
				continue;
			}
			else
			{
				if(_map[i][j])
					book[j]++;
			}
		}
	}
	for(int i=1;i<=N;i++)
	{
		if(book[i]>=(N-1)/2)
		{
			printf("%d ",i);
		}
	}
	
	return 0;	
}

