#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#define il inline
#define rgi register long long
#define ll long long
using namespace std;
const ll maxn = 100005;
ll n;
ll stk[maxn], que[maxn], head, tail, top;
priority_queue <ll> grh, lsh;
bool s, q, g, l;
int main()
{
	scanf("%lld", &n);
	s = 1, q = 1, g = 1, l = 1;
	head = 1;
	for(rgi i = 1; i <= n; ++i)
	{
		ll opt, num;
		scanf("%lld%lld", &opt, &num);
		if(opt == 1) //²åÈë
		{
			if(s)
				stk[++top] = num;
			if(q)
				que[++tail] = num;
			if(g)
				grh.push(num);
			if(l)
				lsh.push(-num);
		}
		else
		{
			if(s)
			{
				if(top <= 0)
					s = 0;
				if(stk[top] != num)
					s = 0;
				--top;
			}
			if(q)
			{
				if(head > tail)
					q = 0;
				if(que[head] != num)
					q = 0;
				++head;
			}
			if(g)
			{
				if(grh.empty())
					g = 0;
				if(grh.top() != num)
					g = 0;
				grh.pop();
			}
			if(l)
			{
				if(lsh.empty())
					l = 0;
				if(-lsh.top() != num)
					l = 0;
				lsh.pop();
			}
		}
	}
	if(q)
		printf("Yes\n");
	else
		printf("No\n");
	if(s)
		printf("Yes\n");
	else
		printf("No\n");
	if(g)
		printf("Yes\n");
	else
		printf("No\n");
	if(l)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
