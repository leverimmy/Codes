#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int white,black;

int main()
{
	for(int i=1;i<=64;i++)
	{
		char c;
		cin>>c;
		if(c=='p')
			black++;
		if(c=='n' || c=='b')
			black+=3;
		if(c=='r')
			black+=5;
		if(c=='q')
			black+=9;
		if(c=='P')
			white++;
		if(c=='N' || c=='B')
			white+=3;
		if(c=='R')
			white+=5;
		if(c=='Q')
			white+=9;
	}
	//printf("%d %d\n",white,black);
	if(white>black)
		printf("White");
	else if(white<black)
		printf("Black");
	else
		printf("Draw");
	return 0;
}