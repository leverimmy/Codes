#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int map[6][6];
char s[100];
int ino,jno;
int n;
char t;

int main()
{
	while(scanf("%s",map[1]+1))
	{
		if(map[1][1]=='Z')
			break;
		for(int i=2;i<=5;i++)
			for(int j=1;j<=5;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]==' ')
				{
					ino=i;
					jno=j;
				}
			}
		scanf("%s",s);
		for(int i=0;i<strlen(s)-1;i++)
		{
			if(s[i]=='A')
			{
				map[ino][jno]=map[ino][jno-1];
				map[ino][jno-1]=' ';
				jno=jno-1;
			}
			if(s[i]=='B')
			{
				map[ino][jno]=map[ino][jno+1];
				map[ino][jno+1]=' ';
				jno=jno+1;
			}
			if(s[i]=='L')
			{
				map[ino][jno]=map[ino-1][jno];
				map[ino-1][jno]=' ';
				ino=ino-1;
			}
			if(s[i]=='R')
			{
				map[ino][jno]=map[ino+1][jno];
				map[ino+1][jno]=' ';
				ino=ino+1;
			}
		}
		printf("Puzzle #%d:\n",n);
		for(int i=1;i<=5;i++)
		{
			for(int j=1;j<=5;j++)
				printf("%c",map[i][j]);
			printf("\n");
		}
		return 0;
	}
}