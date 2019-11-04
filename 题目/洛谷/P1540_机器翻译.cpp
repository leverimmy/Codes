#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
bool marked[1000];
int main()
{
	queue<int> q;
	int neicun,n,count=0,i,t;
	//memset(marked,0,sizeof(marked));
	scanf("%d %d",&neicun,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		if(!marked[t])
		{
			count++;
			if(q.size()<neicun)
			{
				marked[t]=1;
				q.push(t);
			}
			else
			{
				marked[q.front()]=0;
				marked[t]=1;
				q.pop();
				q.push(t);
			}
		}
	}
	printf("%d",count);
	return 0;
}