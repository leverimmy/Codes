#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

set<string> dict;

int main()
{
	string s;
	while(cin>>s)
	{
		for(int i=0;i<s.length();i++)
		{
			if(isalpha(s[i]))
				s[i]=tolower(s[i]);
			else
				s[i]=' ';
		}
		dict.insert(s);
	}
	for(set<string>::iterator it=dict.begin();it != dict.end();it++)
		cout<<*it<<"\n";	
	return 0;
}