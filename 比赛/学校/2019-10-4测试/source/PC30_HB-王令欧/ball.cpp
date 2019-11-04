#include <cstdio>
#include <iostream>
using namespace std;
const int mod=1e9+7;
int n,m,k;
long long cal(int a, int b)//a个数里面取b个数
{
    long long suma=1,sumb=1,sumc=1;
    /*
    c(n,m)=n!/((n-m)!m!)
    */
	if(b==1 || b==a-1)
		return a;
	if(b==0)
		return 1;
	if(b==2 || b==a-2)
		return (a*a-a)/2;
    for(int i=1;i<=a;i++)
        suma=suma*i%mod;
    for(int i=1;i<=a-b;i++)
        sumb=sumb*i%mod;
    for(int i=1;i<=b;i++)
        sumc=sumc*i%mod;
    return (suma/((sumb*sumc)%mod))%mod;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
    cin>>n>>m>>k;
    cout<<cal(n-k,m-1)%mod;
}
