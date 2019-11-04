#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int ans[110],len,q;
string s;

int check(int k)
{
	for(int i=0;i+k<len;i++)
		if(s[i]!=s[i+k])
			return 0;
	return 1;
}

int main()
{
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>s;
		len=s.length();
		ans[i]=len;
		for(int t=1;t<len;t++)
		{
			if(len%t==0 && check(t)==1)
			{
				ans[i]=t;
				break;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<ans[i]<<endl;
		if(i!=q)
			cout<<endl;
	}
	return 0;
}