#include <cstdio>
#include <cstring>

using namespace std;

const char _not[]=" -- is not a palindrome.";
const char pal[]=" -- is a regular palindrome.";
const char mir[]=" -- is a mirrored string.";
const char mirpa[]=" -- is a mirrored palindrome.";
const char table[]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char s[10010];

char rev(char ch)
{
	if('A'<=ch && ch<='Z')
		return table[ch-'A'];
	else
		return table[ch-'0'+25];
}

int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(scanf("%s",s)==1)
	{
		int len=strlen(s);
		int is_pal=1,is_mir=1;
		for(int i=0;i<((len+1)>>1);i++)
		{
			if(s[i]!=s[len-i-1])
				is_pal=0;
			if(rev(s[i])!=s[len-i-1])
				is_mir=0;
		}
		if(is_pal && is_mir)
			printf("%s%s\n",s,mirpa);
		else if(!is_pal && is_mir)
			printf("%s%s\n",s,mir);
		else if(is_pal && !is_mir)
			printf("%s%s\n",s,pal);
		else
			printf("%s%s\n",s,_not);
		printf("\n");
	}
	return 0;
}