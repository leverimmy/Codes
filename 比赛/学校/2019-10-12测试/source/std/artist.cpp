#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iomanip>
#define N 1000010
using namespace std;
double a[N],b[N];
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,x,y;
	double tota=0,totb=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf",&a[i],&b[i]);
		if(a[i]<1e-6&&b[i]<1e-6) {n--,i--;continue;}
		tota+=a[i],totb+=b[i];
	}
	double T;
	scanf("%lf",&T);
	double A=0,B=tota,C=0,D=totb,p,q;
	double ans=1e18;
	for(i=1;i<n;i++)
	{
		A+=a[i];C+=b[i];B-=a[i];D-=b[i];
		if(A<=D) p=T;
		else p=(C+D)*T/(A+C);
		q=((C+D)*T-(A+C)*p)/(B+D);
		if(A*p+B*q<ans) ans=A*p+B*q;
		printf("%.2lf %.2lf\n", p, q);
		
		if(B<=C) q=T;
		else q=(C+D)*T/(B+D);
		p=((C+D)*T-(B+D)*q)/(A+C);
		if(A*p+B*q<ans) ans=A*p+B*q;
		printf("%.2lf %.2lf\n", p, q);
	}
	printf("%.2lf",ans);
}
