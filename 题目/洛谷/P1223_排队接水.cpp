#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct shui
{
    int num;
    int time;
}a[10000];
bool cmp(shui a,shui b)
{
    return a.time<b.time;
}
int main()
{
    int i,n,j;
	long long int sum=0;
    double aver=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i].time;
        a[i].num=i;
    }
    sort(a+1,a+n+1,cmp);
    for(i=1;i<=n;i++)
        cout<<a[i].num<<" ";
    for(i=n-1;i>0;i--)
    {
        j=n-i;
        sum=sum+a[j].time*i;
    }
    aver=sum/1.0/n;
    printf("\n%.2lf",aver);
    system("pause");
    return 0;
}