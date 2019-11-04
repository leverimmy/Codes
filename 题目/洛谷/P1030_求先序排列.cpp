#include <cstdio>
#include <cstring>

using namespace std;

char pre[10],in[10],post[10];
int len;

int find(char c)
{
	for(int i=0;i<len;i++)
		if(in[i]==c)
			return i;
}

void search(int l1,int r1,int l2,int r2)
{
	int pos=find(post[r2]);
	printf("%c",post[r2]);
	if(pos>l1)
		search(l1,pos-1,l2,r2-r1+pos-1);
	if(pos<r1)
		search(pos+1,r1,r2-r1+pos,r2-1);
}

int main()
{
	scanf("%s",in);
	scanf("%s",post);
	len=strlen(in);
	search(0,len-1,0,len-1);
	return 0;
}