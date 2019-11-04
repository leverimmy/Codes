#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int t,m;
int w[111000],c[111000],f[111000];
int main()
{
	scanf("%d %d",&t,&m);
	for(int i=1;i<=m;i++)
		scanf("%d %d",&w[i],&c[i]);
	for(int i=1;i<=m;i++)
		for(int v=w[i];v<=t;v++)
			f[v]=max(f[v],f[v-w[i]]+c[i]);
	printf("%d",f[t]);
	return 0;
}