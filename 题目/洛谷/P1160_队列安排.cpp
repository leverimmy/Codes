#include <cstdio>

using namespace std;

int n,m;

struct node{
	int pre;
	int next;
}list[100010];

void add(int num,int k,int op)
{
	if(op==0)
	{
		k=list[k].pre;
		list[num].pre=k;
		list[num].next=list[k].next;
		list[list[k].next].pre=num;
		list[k].next=num;
	}
	else if(op==1)
	{
		list[num].pre=k;
		list[num].next=list[k].next;
		list[list[k].next].pre=num;
		list[k].next=num;
	}
}

void del(int num)
{
	if(list[num].pre!=-1)
	{	
		list[list[num].pre].next=list[num].next;
		list[list[num].next].pre=list[num].pre;
		list[num].pre=-1;
	}
}

int main()
{
	list[0].pre=-1;
	list[0].next=1;
	list[1].pre=0;
	list[1].next=-1;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int k,p;
		scanf("%d %d",&k,&p);
		add(i,k,p);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int remove;
		scanf("%d",&remove);
		del(remove);
	}
	for(int i=list[0].next;i!=-1;i=list[i].next)
		printf("%d ",i);
	return 0;
}