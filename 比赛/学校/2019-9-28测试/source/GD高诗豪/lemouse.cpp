#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[1020][1020];
int ans[1020][1020][2];
int main()
{
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  	scanf("%d",&f[i][j]);
	for(int i=0;i<=1010;i++) ans[0][i][0] = ans[i][0][0] = 
	ans[i][0][1] = ans[0][i][1] = 0x7ffffff; 
	ans[1][1][0] = ans[1][1][1]= f[1][1]+f[1][2]+f[2][1];
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    if(i+j>2)
	    {
	    	ans[i][j][0] = ans[i][j][1] = f[i][j+1] + f[i+1][j];
	    	ans[i][j][0] += min(ans[i-1][j][0] + f[i][j-1],ans[i-1][j][1]);
	    	ans[i][j][1] += min(ans[i][j-1][1]+f[i-1][j],ans[i][j-1][0]);
		}
	printf("%d\n",min(ans[n][m][0],ans[n][m][1]));
	return 0;
}
/*
3 9
0 0 1 0 0 0 0 0 1
1 1 1 1 1 1 0 1 0
1 0 0 1 0 0 1 0 0 
*/
