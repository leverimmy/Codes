#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <iostream>

using namespace std;

int dots[10];
int bams[10];
int craks[10];
int wind[5];
int dragon[4];
int chow,pong,eye;
int num;

int main()
{
	for(int i=1;i<=13;i++)
	{
		if(num==0)
			break;
		char s[7];
		scanf("%s",&s);
		if(s=="T")		dots[num]++;
		if(s=="S")		bams[num]++;
		if(s=="W")	 	craks[num]++;
		if(s=="DONG")	wind[1]++;
		if(s=="NAN")		wind[2]++;
		if(s=="XI")		wind[3]++;
		if(s=="BEI")		wind[4]++;
		if(s=="ZHONG")	dragon[1]++;
		if(s=="FA")		dragon[2]++;
		if(s=="BAI")		dragon[3]++;
	}
	
}