#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000010
using namespace std;
int ran(int x)
{
	return ((rand()<<15)+rand())%x+1;
}
int A[N],B[N],C[N];
int ord[N];
int main()
{
	srand(time(0));
	freopen("fantasy10.in","w",stdout);
	int n=50000,m=50000;
	printf("%d %d\n",n,m);
	int i,j,x,y;
	for(i=1;i<=m;i++) ord[i]=i;
	random_shuffle(ord+1,ord+m+1);
	B[m]=A[1]=ran(n);C[m]=ran(n);
	for(i=1;i<m;i++)
	{
		x=ran(n);
		while(x==A[i]) x=ran(n);
		A[i+1]=B[i]=x;
		C[i]=ran(n);
	}
	for(i=1;i<=m;i++)
	if(ran(2)==1) swap(B[i],C[i]);
	for(i=1;i<=m;i++)
	printf("%d %d %d\n",A[ord[i]],B[ord[i]],C[ord[i]]);
}