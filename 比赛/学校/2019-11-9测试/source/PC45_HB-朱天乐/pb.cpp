#include <iostream>
using namespace std;
int n,w;
int u[105]={0};
double sum=0;
double ans=0;
double c[105];
int k[105]={0};
int sm(){
	int hum=0;
	int s=0;
	for(int i=1;i<=w;i++){
		s+=k[i];
		for(int j=k[i-1]+1;j<=k[i];j++){
			hum+=s*u[j];
		}
	}
	for(int i=k[w]+1;i<=n;i++){
		hum+=n*u[i];
	}
	return hum;
}
int search(){
	int ans=100000;
	while(k[1]!=n-w){
		ans=min(ans,sm());
		for(int i=w;i>=1;i--){
			if(k[i]!=n-w+i-1){
				k[i]++;
				break;
			}
		}
	}
	k[1]=n-w;
	ans=min(ans,sm());
	return ans;
}
void qsort(int l,int r)
{  
	int i,j;
	int mid,p;
    i=l; 
    j=r; 
    mid=u[(l+r) / 2];
    do
    {
		while (u[i]>mid) i++;
		while (u[j]<mid) j--;
		if (i<=j) 
        {
			p=u[i];
            u[i]=u[j];
            u[j]=p;
            i++;
            j--;
        }
    }
    while (i<=j);      
    if (l<j)  qsort(l,j);
    if (i<r)  qsort(i,r);
}
int main(){
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	cin>>n>>w;
	w-=1;
	for(int i=1;i<=n;i++){
		cin>>u[i];
		sum+=u[i];
	}
	qsort(1,n);
	for(int i=1;i<=w;i++){
		k[i]=i;
	}
	ans=search();
	ans/=sum;
	printf("%.4f",ans);
	return 0;
}
