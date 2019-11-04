#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <iostream>

using namespace std;

stack <int> s;
char ch;
int num;


int main()
{
	while(scanf("%c",&ch)==1)
	{
		if(ch=='@')
			break;
		switch(ch)
		{
			int x,y;
			case '+':
				x=s.top();	s.pop();
				y=s.top();	s.pop();
				s.push(x+y); break;
			case '-':
				x=s.top();	s.pop();
				y=s.top();	s.pop();
				s.push(y-x); break;
			case '*':
				x=s.top();	s.pop();
				y=s.top();	s.pop();
				s.push(x*y); break;
			case '/':
				x=s.top();	s.pop();
				y=s.top();	s.pop();
				s.push(y/x); break;
			case '.' :
				s.push(num);	num=0; break;
			default:
				num=10*num+ch-'0';
		}
	}
	printf("%d",s.top());
	return 0;
}