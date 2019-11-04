#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,m;
int w[1111];
int c[1111];
int f[81111];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d %d",&w[i],&c[i]);
	for(int i=1;i<=m;i++)
		for(int j=n;j>=w[i];j--)
				f[j]=max(f[j],f[j-w[i]]+c[i]*w[i]);
	printf("%d",f[n]);
}