#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    long long n;
    cin>>n;
	for(long long i=sqrt(2*n);i>=2;i--)
	{
        if((2*n)%i==0 && ((2*n)/i)%2!=i%2 && ((2*n)/i-i+1)/2>0)
		{
            cout<<((2*n)/i-i+1)/2<<' '<<((2*n)/i+i-1)/2;
            return 0; 
		}
	}
	cout<<n<<' '<<n;
    return 0;
}