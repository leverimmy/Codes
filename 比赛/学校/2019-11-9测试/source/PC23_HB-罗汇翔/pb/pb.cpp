#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int inf=2147483647;
int n,w;
double u[110];
double c[110];
double sum;
stack<double>s[110];
double add[110];
double ans;
void work(int i)
{
	if(i>n)
	{
		for(int j=1;j<=w;j++)if(s[j].size()==0)return;
		double k=0,d=0;
		for(int j=1;j<=w;j++)
		{
			k+=s[j].size();
			d+=k*add[j];
		}
		ans=min(ans,d);
		return;
	}
	for(int j=1;j<=w;j++)
	{
		add[j]+=c[i];
		s[j].push(c[i]);
		work(i+1);
		s[j].pop();
		add[j]-=c[i];
	}
}
int main()
{
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	cin>>n>>w;
	ans=inf;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i];
		sum+=u[i];
	}
	for(int i=1;i<=n;i++)c[i]=u[i]/sum;
	work(1);
	printf("%.4lf\n",ans);
	return 0;
} 
