#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

long long a1,a2,a3,ans;
set<long long> b;
set<pair<long long,long long> > c;

template<typename X> 
pair<X,X> makepair(X a,X b)
{
	return pair<X,X>(a,b);
}

int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	
	cin >> a1 >> a2;
	b.insert(a1);
	b.insert(a2);
	ans++;
	if(a1!=a2)
		ans++;
	while(!c.count(makepair(a1,a2)))
	{
		c.insert(makepair(a1,a2));
		a3 = abs(a1-a2);
		a1 = a2;
		a2 = a3;
		if(!b.count(a3))
		{
			b.insert(a3);
			ans++;
		}
	}
	cout << ans;
	return 0;
} 
