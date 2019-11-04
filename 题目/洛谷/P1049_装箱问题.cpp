#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int v,n;
int vol[1001];
int f[21001];
int main()
{
	scanf("%d %d",&v,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&vol[i]);
	for(int i=1;i<=n;i++)
		for(int j=v;j>=vol[i];j--)
			if(j>=vol[i])
				f[j]=max(f[j],f[j-vol[i]]+vol[i]);
	printf("%d",v-f[v]);
}