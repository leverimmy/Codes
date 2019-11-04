#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

char Adui[110],Bdui[110];
char s[110];
int scoreA,scoreB;
int n;

int main()
{
	scanf("%d",&n);
	scanf("%s",Adui);
	scoreA++;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%s",s);
		if(strcmp(Adui,s)!=0)
		{
			strcpy(Bdui,s);
			scoreB++;
		}
		else
			scoreA++;
	}
	if(scoreA>scoreB)
		puts(Adui);
	else
		puts(Bdui);
	return 0;
}