#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int book[25][25][25];
int a1,b1,c1;

int w(int a,int b,int c)
{
	if(a<=0 || b<=0 || c<=0)
		return 1;
	if(a>20 || b>20 || c>20)
		return w(20,20,20);
	if(book[a][b][c]==0)
	{
		if(a<b && b<c)
			book[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
		else
			book[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	}
	return book[a][b][c];
}

int main()
{
	while(1)
	{
		scanf("%d %d %d",&a1,&b1,&c1);
		if(a1==-1 && b1==-1 && c1==-1)
			break;
		else
		{
			printf("w(%d, %d, %d) = %d\n",a1,b1,c1,w(a1,b1,c1));
		}
	}
	return 0;
}