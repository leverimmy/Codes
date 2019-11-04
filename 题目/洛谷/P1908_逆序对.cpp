#include <cstdio>
#define ll long long

using namespace std;

ll n,cnt;
ll a[500010],temp[500010];

void Debug()
{
	for(ll i=1;i<=n;i++)
		printf("%lld ",a[i]);
}

void merge_sort(ll left,ll right)
{
	if(right-left>1){
	ll mid=(left+right)/2;
	//ll mid=left+(right-left)/2;
	ll p=left,q=mid,i=left;
	merge_sort(left,mid);
	merge_sort(mid,right);
	while(p<mid || q<right)
	{
		if(q>=right || (p<mid && a[p] <= a[q]))
			temp[i++]=a[p++];
		else
		{
			temp[i++]=a[q++];
			cnt+=mid-p;
		}
	}
	for(ll i=left;i<right;i++)
		a[i]=temp[i];
	}
}

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	merge_sort(1,n+1);
	/*Debug()*/
	printf("%lld",cnt);
	return 0;
}