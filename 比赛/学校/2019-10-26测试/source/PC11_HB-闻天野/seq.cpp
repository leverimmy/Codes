#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,m,ans=0;
long long a[10007],b[10007];
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>n>>m;
	a[1]=n;
	a[2]=m;
	for(int i=1;i<=10007;i++)
	{
		b[i]=1;
		a[i+2]=abs(a[i+1]-a[i]);
		cout<<a[i];
	    for(int j=1;j<=i-1;j++)
        {
            if(a[i]==a[j])
		    {
    	        b[i]=1;
      	        break;
            }
            else
            {
                b[i]=2;
            }
            if(b[i]==2)
            {
                ans++;
            }
	    }
    }
	cout<<ans+1;
	return 0;
}
