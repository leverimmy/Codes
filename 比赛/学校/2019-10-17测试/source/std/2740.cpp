#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
 
int n,k;
long long ans=0,mea;
int a[1001010];
bool tf[1000010];
int nowa[1000010];
long long temp[1000010];
 
long long get_ans(int x){
	int t=0;
	while(!tf[x]){
		tf[x]=true;
		nowa[++t]=a[x];
		x+=k;if(x>n) x-=n;
	}
	temp[1]=0;
	for(int i=2;i<=t;i++) temp[i]=temp[i-1]+nowa[i-1]-mea;
	sort(temp+1,temp+1+t);
	long long s1=-temp[(t+1)/2],nowans=0;
	for(int i=1;i<=t;i++) nowans+=abs(temp[i]+s1);
	return nowans;
}
 
int main(){
		freopen("2740.in","r",stdin);
		freopen("2740.out","w",stdout);
	scanf("%d %d",&n,&k);k++;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),mea+=a[i];mea/=n;
	for(int i=1;i<=n;i++){
		if(tf[i]) continue;
		ans+=get_ans(i);
	}
	printf("%lld\n",ans);
	return 0;
}
