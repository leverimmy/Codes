#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int num[10000000];
int book[10000000];
int len;

int power(int base,int p)
{
	if(p==0)	return 1;
	else return power(base,p-1)*base;
}

int main()
{
	/*-----------------GENERATOR-----------------*/
	
	freopen("gen.out","w",stdout);
	for(int a=2;a<=10000000;a++)
		for(int d=2;d<=log(10000000)/log(a);d++)
		{
			if(power(a,d)<=10000000 && book[power(a,d)]!=1)
			{
				num[len++]=power(a,d);
				book[power(a,d)]=1;
			}
		}
	sort(num+1,num+len+1);
	for(int i=1;i<=len;i++)
		printf("%d,",num[i]);
	return 0;
}