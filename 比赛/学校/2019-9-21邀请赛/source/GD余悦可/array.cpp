#include<bits/stdc++.h>
#define N 200001

using namespace std;
int a[N],p,cnt,m,n,k;

int main()
{
	
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);//*/
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&p,&k);
		cnt=0;
		while(n>=p)
		{
			cnt++;
			p+=a[p]+k;
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}



/*

3 
1 1 1 
3 
1 1 
2 1 
3 1 


*/
