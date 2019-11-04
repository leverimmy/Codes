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

char s1[1000010],s2[1000010];
int next_array[1000010];
int len1,len2;

void print_s(){
	for(int i=1;i<=len2;i++)
		printf("%d ",next_array[i]);
}

void NEXT(){
	int j=0;
	for(int i=2;i<=len2;i++)
	{
		while(j>0 && s2[j+1]!=s2[i])
			j=next_array[j];
		if(s2[j+1]==s2[i])
			j++;
		next_array[i]=j;
	}
}

void KMP(){
	int j=0;
	for(int i=1;i<=len1;i++)
	{
		while(j>0 && s2[j+1]!=s1[i])
			j=next_array[j];
		if(s2[j+1]==s1[i])
			j++;
		if(j==len2)
		{
			printf("%d\n",i-len2+1);
			j=next_array[j];
		}
	}
}

int main()
{
	cin>>s1+1;
	cin>>s2+1;
	len1=strlen(s1+1);
	len2=strlen(s2+1);
	NEXT();
	KMP();
	print_s();
	return 0;
}