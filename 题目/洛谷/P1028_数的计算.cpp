#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int n,num[3000];
int dfs(int n)
{
	int ans=1;
	if(num[n]!=-1)
		return num[n];
	for(int i=1;i<=n/2;i++)
		ans+=dfs(i);
	num[n]=ans;
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	num[1]=1;
	memset(num,-1,sizeof(num));
	printf("%d",dfs(n));
	return 0;
}
/*
递推
int n,cnt=1,i,f[1111];
f[0]=f[1]=1;
scanf("%d",&n);
for(i=2;i<=n;i++)
{
	if(i%2==0)
		f[i]=f[i]+f[i/2];
	else
		f[i]=f[i-1];
}
printf("%d",f[n]);
*/