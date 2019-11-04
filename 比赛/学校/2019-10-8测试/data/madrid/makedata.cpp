#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ran(int x)
{
	return ((rand()<<15)+rand())%x+1;
}
double rad(int x)
{
	return (double)(ran(x*100+1)-1)/100;
}
int main()
{
	srand(time(0));
	freopen("madrid10.in","w",stdout);
	int n=50000,m=50000,t1=0,t2=0,t3=0;
	printf("%d\n",n);
	int i,j,o,x,y;
	for(i=1;i<=n;i++)
	printf("%.2lf %.2lf\n",rad(200)-100,rad(200)-100);
	printf("%d\n",m);
	while(m--)
	{
		if(t2==1) o=ran(3);
		else if(t3==1) o=ran(4);
		else o=ran(5);
		if(t1==1) x=1,y=n;
		else
		{
			x=ran(n);y=ran(n);
			while(abs(y-x)<=n/2) {y=ran(n);x=ran(n);}
			if(x>y) swap(x,y);
		}
		if(o==1) printf("M %d %d %.2lf %.2lf\n",x,y,rad(200)-100,rad(200)-100);
		else if(o==2) printf("X %d %d\n",x,y);
		else if(o==3) printf("Y %d %d\n",x,y);
		else if(o==4) printf("O %d %d\n",x,y);
		else printf("R %d %d %.2lf\n",x,y,rad(360));
	}
}