#include<iostream>
using namespace std;
int T,n,m,x,y,k;
bool ans;
void check()
{
	
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		ans=1;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&k);
			if(x==y&&k==1){ans=0;break;}
			check();
		}
		if(ans==1)printf("Yes");
		else printf("No");
	} 
}
