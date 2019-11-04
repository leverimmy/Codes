#include <cstdio>

int i;
char ch;
char ans[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
	while((ch=getchar())!=EOF)
	{
		for(i=1;ans[i] && ans[i]!=ch;i++);
		if(ans[i])
			putchar(ans[i-1]);
		else
			putchar(ch);
	}
	return 0;
}