#include <bits/stdc++.h>
using namespace std;

int read()
{
	int res=0,p=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')p=-1; ch=getchar();}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*p;
}

int n,w,sum,u[110];
int ans;

int main()
{
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	n=read(),w=read();
	for(int i=1;i<=n;i++) u[i]=read(),sum+=u[i];
	sort(u+1,u+n+1);
	int num=0,id=0,cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(num+u[i]>sum/w && cnt<w)
		{
			ans+=num*id;
			num=0;
			cnt++;
		}
		num+=u[i],id++;
	}
	ans+=num*id;
	double k=ans*1.0/sum;
	printf("%.4lf",k);
	return 0;
}
