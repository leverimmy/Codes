#include <cstdio>
#include <cstring>
using namespace std;
struct shu
{
	char lc;
	char rc;
	char me;
}tree[1000];
void pre(char a)
{
	printf("%c",a);
	if(tree[a].lc!='*')	
		pre(tree[a].lc);
	if(tree[a].rc!='*') 
		pre(tree[a].rc);
}
int main()
{
	int n,i;
	char c,fir;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		{
			scanf(" %c",&c);
			if(i==1)
				fir=c;
			scanf(" %c%c",&tree[c].lc,&tree[c].rc);
			tree[tree[c].lc].me=c;
			tree[tree[c].rc].me=c;
		pre(fir);
		}
	system("pause");
	return 0;
}