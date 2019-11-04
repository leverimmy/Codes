#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 100020;
int a[100020];
int f[310][N];
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=0;i<=300;i++)
	  for(int j=n;j>=1;j--)
	    if(j+i+a[j]<=n)
	    f[i][j] = f[i][j+i+a[j]] + 1; 
	else f[i][j] = 1;
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(y<=300) printf("%d\n",f[y][x]);
		else
		{
			int cnt = 0;
			while(x<=n)
			{
				cnt ++;
				x += y+a[x];
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}
/*
3 
1 1 1 
3 
1 302
2 302 
3 100000
*/
