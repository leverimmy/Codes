#include<bits/stdc++.h>
using namespace std;
int l1,l2,l3,l4,ci[10010],minimum=2147483640,m,n,p,ans,t,f[10010],fz,fm;
struct str
{
	int from;
	int to;
	double val;
	int a;
	int b;
}lj[100010];
inline bool cmp(str x,str y)
{
	return x.val<y.val;
}
int find(int n)
{
    if(f[n]==n)
    {
        return n;
    }
    f[n]=find(f[n]);
    return f[n];
}
void combine(int m,int n)
{
    int x,y;
    x=find(m);
    y=find(n);
    f[x]=y;
}
void kruskal()
{
	for(int i=1;t<n-1;i++)
		if(find(lj[i].from)!=find(lj[i].to))
		{
			fz+=lj[i].a;
			fm+=lj[i].b;
			combine(lj[i].from,lj[i].to);
			t++;
		}
}
int main()
{
	freopen("mst.in","r",stdin);
	freopen("mst.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=p;i++)
	{
		cin>>l1>>l2>>l3>>l4;
		lj[i].from=l1;
		lj[i].to=l2;
		lj[i].val=(double)l3/(double)l4;
		lj[i].a=l3;
		lj[i].b=l4;
	}
	sort(lj+1,lj+p+1,cmp);
	kruskal();
	cout<<(double)fz/(double)fm;
	return 0;
}
