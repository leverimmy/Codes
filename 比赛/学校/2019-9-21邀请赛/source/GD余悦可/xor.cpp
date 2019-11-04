#include<bits/stdc++.h>
#define N 100001

using namespace std;
int n,d[N],m,T,c,k;

struct pai{
	int l,r,k;
}a[N];
bool comp(pai x,pai y)
{
	if(x.l<y.l)return 1;
	else if(x.l==y.l)
	{
		if(x.r<y.r)return 1;
		else return 0;
	}
	else return 0;
}

int main()
{
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);//*/
	cin>>T;
	while(T--)
	{
		bool yes=1;
		memset(d,-1,sizeof(d));d[1]=1;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].k);
		}
		sort(a+1,a+m+1,comp);
		for(int i=1;i<=m;i++)
		{
			int temp,g=0;
			for(int j=a[i].l;j<=a[i].r;j++)
			{
				if(d[j]==-1)
				{
					g=j;
					break;
				}
				if(j==a[i].l)temp=d[j];
				else temp=temp^d[j];
			}
			/*
			for(int j=1;j<=n;j++)cout<<d[j]<<" ";
			cout<<endl<<"g= "<<g<<endl;
			cout<<temp<<endl;//*/
			if(g)
			{
				for(int j=g;j<a[i].r;j++)
				{
					d[j]=1;
				}
				d[a[i].r]=a[i].k^d[a[i].r-1];
				if(a[i].l==a[i].r)d[a[i].l]=a[i].k;
			}
			else
			{
				if(temp!=a[i].k)
				{
					yes=0;
					break;
				}
			}
				
		}
		if(yes)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}


/*
2 
3 2 
1 2 1 
2 3 0 
2 3 
1 1 1 
2 2 1 
1 2 1

*/






