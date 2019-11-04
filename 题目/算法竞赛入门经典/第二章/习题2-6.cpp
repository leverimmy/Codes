#include <cstdio>
#include <cmath>

using namespace std;

int book[10];

int main()
{
	for(int a=123;a<=329;a++)
	{
		int flag=1,b=a*2,c=a*3;
		int age=a%10,ashi=a/10%10,abai=a/100;
		int bge=b%10,bshi=b/10%10,bbai=b/100;
		int cge=c%10,cshi=c/10%10,cbai=c/100;
		book[age]=book[ashi]=book[abai]=book[bge]=book[bshi]=book[bbai]=book[cge]=book[cshi]=book[cbai]=1;
		if(book[1]*book[2]*book[3]*book[4]*book[5]*book[6]*book[7]*book[8]*book[9])
			printf("%d %d %d\n",a,b,c);
		book[age]=book[ashi]=book[abai]=book[bge]=book[bshi]=book[bbai]=book[cge]=book[cshi]=book[cbai]=0;
	}
	return 0;
}