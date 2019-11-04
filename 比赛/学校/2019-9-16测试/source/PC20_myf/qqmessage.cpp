#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#define il inline
#define rgi register int
#define sp putchar(' ')
#define el putchar('\n')

using namespace std;
struct node
{
	string user,tim1,tim2;
	char message[1001];
}a[1001];
string user;
int indx=1;

inline bool cmp(node p,node q)
{
	if(p.tim1==q.tim1)
		return p.tim2<q.tim2;
	return p.tim1<q.tim1;
}

signed main()
{
	freopen("qqmessage.in","r",stdin);
	freopen("qqmessage.out","w",stdout);
	cin>>user;
	while(cin>>a[indx].tim1)
	{
		cin>>a[indx].tim2>>a[indx].user;
		if(a[indx].user!=user)
		{
			char sss[1001];
			gets(sss);
			continue;
		}
		//cout<<a[indx].tim1<<endl<<a[indx].tim2<<endl;
		char not_used=getchar();
		gets(a[indx].message);
		++indx;
	}
	sort(a+1,a+indx,cmp);
	for(rgi i=1;i<indx;++i)
		puts(a[i].message);
	return 0;
}

