#include<bits/stdc++.h>
using namespace std;
const int N = 100020;
const int M = 200020;
int cnt=0;
int T;
int n,m;
int f[600][600];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		cnt = 0;
		memset(f,-1,sizeof(f));		  
		bool bo =0;
		for(int i=1;i<=m;i++)
		{
		  int x,y,z,temp;
		  scanf("%d%d%d",&x,&y,&z);
		  if(f[x][y]>=0 && z!=f[x][y])
		  {
		  	printf("No\n");
		  	bo = 1;
		  	break;
		  }
		  else f[x][y] = z;
		}
		if(bo) continue;
		for(int k=1;k<n;k++)
		  for(int i=1;i<=n-k+1;i++)
		  {
		  	int j = i+k;
		  	for(int l=i;l<j;l++)
		  	  if(f[i][l]!=-1 && f[l+1][j]!=-1)
		  	  {
				if(f[i][j] !=-1)
				{
		  	    if(f[i][j] != (f[i][l] ^ f[l+1][j])) 
		  	    {
		  	    	bo = 1;
					  break;
				  }
				}
				else f[i][j] = f[i][l]^f[l+1][j];
		  	}
		  }
		if(bo) printf("No\n");    
		 else  printf("Yes\n");
	}
	return 0;
}
/*
2 
3 2 
1 2 1 
2 3 0 
2 2 
1 2 1
2 2 1
*/
