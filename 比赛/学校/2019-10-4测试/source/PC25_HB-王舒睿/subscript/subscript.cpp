#include <iostream>
#include<cstdio>
#include<cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main()
{
	freopen("subscript.in","r",stdin);
	froepen("subscript.out","W",stdout);
	int t;
	int a;
	cin>>t;
	for(a=1;a<=t;a++)
	{
		char c[1000001];
		for(int p=0;p<=100000;p++)
			c[p]='0';
		cin>>c;
		if(c[3]=='0')
			cout<<c;
		else if(c[3]==']')
		{
			if(c[1]=='['&&c[3]==']')
			{
				if(c[0]<=c[2])
					cout<<c;
				else
					cout<<c[2]<<'['<<c[0]<<']';
			}
			else
				cout<<c;
		}
		else if(c[1]=='['&&c[4]==']')
		{
			if(c[0]<=c[2])
				cout<<c;
			else
				cout<<c[2]<<c[3]<<'['<<c[0]<<']';	
		}
		else if(c[2]=='['&&c[4]==']')
		{
			if(c[0]<=c[2])
				cout<<c;
			else
				cout<<c[3]<<'['<<c[0]<<c[1]<<']';
		}
		else
			cout<<c;
	}
	
	return 0;
}
