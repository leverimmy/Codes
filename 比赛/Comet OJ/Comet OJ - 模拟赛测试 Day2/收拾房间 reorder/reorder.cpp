#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, m;
int a[N], vis[N];

vector <int> vec;

struct STACK
{
	static const int MAX_SIZE = 2e6;
	int _top, stk[MAX_SIZE + 10];
	void clear(){_top = 0;}
	void push(int val){stk[++_top] = val;}
	void pop(){_top--;}
	int top(){return stk[_top];}
	int size(){return _top;}
	bool empty(){return _top == 0;}
	STACK(){clear();}
} stk;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		a[i] = read();
		vis[a[i]] = 1;
	}
	for(rgi i = n; i >= 1; --i)
		if(!vis[i]) stk.push(i);
	for(rgi i = 1; i <= m; ++i)
	{
		while(!stk.empty())
		{
			if(stk.top() < a[i])
			{
				vec.push_back(stk.top());
				stk.pop();
			}
			else
				break;
		}
		vec.push_back(a[i]);
	}
	while(!stk.empty())
	{
		vec.push_back(stk.top());
		stk.pop();
	}
	for(vector <int> :: iterator it = vec.begin(); it != vec.end(); ++it)
		printf("%d\n", *it);
	return 0;
}
/*
5 3
1
4
2

*/
