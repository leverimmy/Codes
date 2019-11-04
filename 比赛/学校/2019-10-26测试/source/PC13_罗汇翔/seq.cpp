#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
long long a1,a2,a3;
set<long long>s;
int main() 
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>a1>>a2;
	s.insert(a1);
	s.insert(a2);
	for(int i=1;i<=1E6;i++)
	{
		a3=abs(a1-a2);
		s.insert(a3);
		a1=a2;
		a2=a3;
	}
	cout<<s.size();
	return 0;
}
