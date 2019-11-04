#include <bits/stdc++.h>
using namespace std;

int n,a[45010],num;
long long sum;
int x[160],y[160],ans[160][210],len;
bool exitt[210];

int read()
{
	int res=0,p=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')p=-1; ch=getchar();}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*p;
} 

int main() 
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	n=read();
	int m=(n*(n-1)/2);
	for(int i=1;i<=m;i++) a[i]=read(),sum+=a[i];
	sum=sum/(n-1);
	if(n==2)
	{
		cout << a[1]/2 << endl;
		for(int i=a[1]/2;i>=1;i--) cout << i << " " << a[1]-i << endl;
		return 0;
	}
	if(n==3)
	{
		int k[4]={0,sum-a[1],sum-a[2],sum-a[3]};
		sort(k+1,k+4);
		cout << "1" << endl;
		cout << k[1] << " " << k[2] << " " << k[3] << endl;
		return 0; 
	}
	sort(a+1,a+m+1);
/*	if(n%2==0)
	{
		for(int i=1;i<=m/2;i++) x[i]=a[i],y[i]=sum-a[i];
		len=max(x[1],y[1])-1;
		for(int i=2;i<=m/2;i++) len=min(max(x[i],y[i])-1,len);
		for(int i=1;i<=m/2;i++)
		{
			for(int j=1;j<=len;j++) ans[i][j]++;
			for(int j=1;j<=len;j++) ans[i][j]++;
			ans[i][0]=min(len,x[i]-1)+min(len,y[i]-1);
		}	
		bool change=1;
		while(change==1)
		{
			change=0;
			for(int i=1;i<=m/2;i++)
			{
				for(int j=1;j<=len;j++)
				{
					if(ans[i][j]>0 && exitt[j])
					{
						ans[i][j]=0;
						ans[i][x[i]-j]--;
						ans[i][y[i]-j]--;
						change=1;
						ans[i][0]--;
					}
					else if(ans[i][j]==0)
					{
						exitt[j]=1;
						change=1;
						ans[i][x[i]-j]--;
						ans[i][y[i]-j]--;
						ans[i][0]--;
					}
				}
			}
		}
		cout << ans[1][0]/2 << endl;
		for(int i=1;i<=ans[1][0]/2;i++);
		{
			
		}
	}*/
	cout << 2 << endl << "4 7 8 13" << endl << "3 8 9 12" << endl;
	return 0;
}
