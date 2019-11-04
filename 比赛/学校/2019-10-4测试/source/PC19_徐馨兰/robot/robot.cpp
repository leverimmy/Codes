#include <bits/stdc++.h>
using namespace std;

int read()
{
	int res=0,p=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')p=-1; ch=getchar();}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*p;
}

int n,a[1010],m1,m2,cnt1,cnt2;

int main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]<a[i-1]) cnt1++;
		if(a[i]>a[i-1]) cnt2++;
	}
	cout << min(cnt1*m1,cnt2*m2) << endl;
	return 0;
}
