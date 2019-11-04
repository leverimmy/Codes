#include<bits/stdc++.h>
using namespace std;
int n,f[100005],a[100005],m,p,k;
int main()
{
  freopen("array.in","r",stdin);
  freopen("array.out","w",stdout);	
   cin>>n;
   for (int i=1;i<=n;i++)
     scanf("%d",&a[i]);
     int x=0;
   for (int i=n;i>=1;i--)
   {
   	 x=a[i];
   	 if (i+x>n) f[i]=1;
   	 else f[i]=f[i+x]+1;
   }
   scanf("%d",&m);
   for (int i=1;i<=m;i++)
   {
   	  scanf("%d%d",&p,&k);
   	  if (k<=100&&k>0)
   	  {
   	  	int s=0;
   	  	while (p<=n)
   	  	{
		  p+=a[p]+k;
		  s++;
		 }
   	  	printf("%d\n",s);
   	  }
   	  if (k==0)
   	  {
   	    printf("%d\n",f[p]);
   	  }
   }
   return 0;
}
