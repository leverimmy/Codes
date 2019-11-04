#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
char s[2];

int main()
{
	freopen("subscript.in","r",stdin);
	freopen("subscript.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		for(int i=1;i<=2;i++)
			cin>>s[i];
		if(s[1]<s[2]) cout<<s[1]<<s[2]<<endl;
		else cout<<s[2]<<s[1]<<endl;
	}
	return 0;
}
