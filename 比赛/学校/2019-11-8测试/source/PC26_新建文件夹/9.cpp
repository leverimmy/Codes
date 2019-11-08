#include <bits/stdc++.h>
using namespace std;

const int MAXN=1000005;

int heap[MAXN],siz;

void push(int val)
{
	siz++;
	heap[siz]=val;
	int NowNode=siz;
	while(NowNode>>1)
	{
		int NextNode=NowNode>>1;
		if(heap[NextNode]<heap[NowNode])
		{
			swap(heap[NextNode],heap[NowNode]);
			NowNode=NextNode;
		}
		else
		{
			break;
		}
	}
}
void pop()
{
	swap(heap[1],heap[siz]);
	siz--;
	int NowNode=1;
	while((NowNode<<1)<=siz)
	{
		int NextNode=NowNode<<1;
		if(NextNode+1<=siz&&heap[NextNode]<heap[NextNode+1])
		{
			NextNode++;
		}
		if(heap[NextNode]>heap[NowNode])
		{
			swap(heap[NextNode],heap[NowNode]);
			NowNode=NextNode;
		}
		else
		{
			break;
		}
	}
}
int top()
{
	return heap[1];
}

int main()
{
	freopen("9.in","w",stdin);
	freopen("9.out","r",stdout);
	int Q;
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==1)
		{
			int k;
			scanf("%d",&k);
			push(k);
		}
		else
		{
			if(siz==0)
			{
				printf("-1\n");
				continue;
			}
			printf("%d\n",top());
			pop();
		}
	}
	return 0;
}

