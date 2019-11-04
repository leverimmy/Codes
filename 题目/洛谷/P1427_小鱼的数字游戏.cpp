#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
int main()
{
	stack<int> s;
	while(1)
	{
		int t;
		scanf("%d",&t);
		if(t!=0)
			s.push(t);
		else
			break;
	}
	while(!s.empty())
	{
		printf("%d ",s.top());
		s.pop();
	}
	return 0;
}