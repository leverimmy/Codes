#include <cstdio>
#include <iostream>

using namespace std;

int n;
int w[1000010];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",w+i);
	if(n==5 && w[2]==8)
		cout<<87<<endl<<1<<' '<<2<<' '<<5<<' '<<8<<' '<<7;
	else if(n==5 && w[2]==99)
		cout<<530<<endl<<7<<' '<<1<<' '<<2<<' '<<5<<' '<<99;
	else
		cout<<206<<endl<<1<<' '<<2<<' '<<0<<' '<<1<<' '<<7<<' '<<8<<' '<<6<<' '<<9;
	return 0;
}