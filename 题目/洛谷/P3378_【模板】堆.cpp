#include <cstdio>
#include <cstring>
#define maxn 1000010
#define rgi register int
#define il inline
#define swap(a,b) a^=b^=a^=b

using namespace std;

int n, siz;
int h[maxn];//堆

il void push(int val)
{
	h[++siz] = val;//往队尾添加元素
	int cur = siz;//cur表示当前要向上调整的节点编号，初始化为队尾编号
	while(cur >= 1)//当cur不是堆顶的时候循环
	{
		if(h[cur]<h[cur >> 1])//如果自己的父亲比自己大
			swap(h[cur], h[cur >> 1]);//交换
		else
			break;//如果无法交换，则表明已经调整完毕
		cur >>= 1;//开始处理自己的父亲节点
	}
}

il void pop()
{
	swap(h[1], h[siz]);//交换队首与队尾元素
	h[siz--] = 0;//删除
	int cur = 1;//cur表示当前要向下调整的节点编号，初始化为队首编号
	while((cur << 1) <= siz)
	{
		int lc = cur << 1, rc = lc + 1, _next;
		//lc是左儿子编号，rc是右儿子编号，_next是下一步要处理的节点编号（要么是左儿子，要么是右儿子）
		if(rc <= siz)//如果rc没有超siz，就比较lc与rc的大小，交换小的那一个
		{
			if(h[lc] <= h[rc])
				_next = lc;
			else
				_next = rc;
		}
		else//如果rc超了siz，那么只能考虑左儿子了
			_next = lc;
		if(h[_next] < h[cur])//如果下一步要处理的节点比当前节点小
		{
			swap(h[_next], h[cur]);//交换
			cur = _next;//开始处理下一个节点
		}
		else
			break;//如果无法交换，则表明已经调整完毕
	}
}

il int top()
{
	return h[1];//堆顶自然是h[1]
}

int main()
{
	scanf("%d", &n);
	for(rgi i = 1; i <= n; i++)
	{
		int op;
		scanf("%d", &op);
		if(op == 1)
		{
			int v;
			scanf("%d", &v);
			push(v);
		}
		else if(op == 2)
			printf("%d\n", top());
		else if(op == 3)
			pop();
	}
	return 0;
}
