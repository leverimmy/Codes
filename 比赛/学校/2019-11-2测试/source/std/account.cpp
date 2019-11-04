#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e5+5;
int n,d,__A__,__B__,a[N]; 

long long X=1;
int randint(int L,int R) {
	const long long A=__A__,B=__B__;
	X=(X*X+A*X+B)%99824353LL;
	return X%(R-L+1)+L;
}

void Qsort(int A[],int L,int R) {
	if(L>=R)return ;
	int l=L;
	int r=R;
	int index=randint(L,R);
	int key=A[index];
	std::swap(A[l],A[index]);
	while(l<r) {
		while(l<r&&A[r]>=key)--r;A[l]=A[r];
		while(l<r&&A[l]<=key)++l;A[r]=A[l];
	}A[l]=key;
	if(!(l==L||l==R))
		assert(0);
	Qsort(A,L,l-1);
	Qsort(A,l+1,R);	
} 

int main()
{
		freopen("account.in","r",stdin);
		freopen("account.out","w",stdout);
	cin>>n>>__A__>>__B__;
	for(d=1;d<n;d<<=1);d-=1;
	rep(i,1,n)a[i]=i;
	static int ans[N];
	int l=1,r=n,mn=1,ul=1,ur=n;
	rep(tmp,1,n)
	{
		int p=randint(l,r);
		if(a[p]==mn)
		{
			ans[a[p]]=ur--;
			swap(a[p],a[l]);
			swap(a[l],a[r]);
			--r;
		}
		else
		{
			ans[a[p]]=ul++;
			swap(a[p],a[l]);
			++l;
		}
		while(ans[mn])++mn;
	}
	rep(i,1,n)printf("%d%c",ans[i]," \n"[i==n]);
}
