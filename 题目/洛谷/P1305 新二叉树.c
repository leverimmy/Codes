#include<stdio.h>
#include<string.h>
struct node{
	char lc,rc,fa;
}tree[1000];
void work(char s)
{
	printf("%c",s);
	if(tree[s].lc!='*')work(tree[s].lc);
	if(tree[s].rc!='*')work(tree[s].rc);	
}
int main(){
	int i,n;
	char c,fir;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf(" %c",&c);
		if(i==1)fir=c;
		scanf(" %c%c",&tree[c].lc,&tree[c].rc);
		tree[tree[c].lc].fa=c;
		tree[tree[c].rc].fa=c;
	}
	work(fir);	
    system("pause");
   return 0;
}
