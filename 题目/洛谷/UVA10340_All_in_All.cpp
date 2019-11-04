#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

string s,t;

int main()
{
	while(cin>>s>>t)
	{
		queue<char> q;
		int lens=s.length();
		int lent=t.length();
		for(int i=0;i<lens;i++)
			q.push(s[i]);
		for(int i=0;i<lent;i++)
			if(t[i]==q.front())
				q.pop();
		if(q.empty()==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}