#include <cstdio>
#include <cstring>

using namespace std;

char a[300];
int len,b,o,y,g,i,r,l,boy,girl;

int max(int a,int b){return a>b?a:b;}

int main()
{
	scanf("%s",a);
	len=strlen(a);
	for(int z=0;z<len;z++)
	{
		if(a[z]=='b')
			b++;
		if(a[z]=='o')
			o++;
		if(a[z]=='y')
			y++;
		if(a[z]=='g')
			g++;
		if(a[z]=='i')
			i++;
		if(a[z]=='r')
			r++;
		if(a[z]=='l')
			l++;
	}
	boy=max(max(b,o),y);
	girl=max(max(g,i),max(r,l));
	printf("%d\n%d",boy,girl);
	return 0;
}