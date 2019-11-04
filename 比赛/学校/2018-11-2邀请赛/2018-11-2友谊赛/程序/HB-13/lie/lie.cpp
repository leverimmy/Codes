#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxx=100010;
int n,lenn,b[maxx],sum,q,m;
bool check[maxx];
struct data
{
    int t,l,len,r;
}a[maxx];
bool cmp(data a,data b)
{
    if(a.len==b.len)
    {
        return a.r<b.r;
    }
    return a.len<b.len;
}
bool cmpp(int a,int b)
{
    return a>b;
}
int main()
{
	freopen("lie.in","r",stdin);
	freopen("lie.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].t,&a[i].l);
        a[i].len=a[i].l+a[i].t+1;
        a[i].r=a[i].t+1;
        b[a[i].len]++;
    }
    for(int i=1;i<=100000;i++)
    {
    	if(m<b[i])
    	{
    		m=max(m,b[i]);
			q=i;
		}
	}
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(a[i].len!=q)
        {
            sum++;
            if(!check[a[i].r])
            {
                check[a[i].r]=1;
            }
            continue;
        }
        else if(!check[a[i].r])
        {
            check[a[i].r]=1;
        }
        else if(check[a[i].r]>1) sum++;
    }
    printf("%d",sum);
    return 0;
}
