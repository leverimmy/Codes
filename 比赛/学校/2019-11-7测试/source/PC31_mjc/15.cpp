#include<bits/stdc++.h>
using namespace std;

int n,r,m;
char ch;
int a[1000010];
int pos,ans;
int main(){
	freopen("15.in","r",stdin);
	freopen("15.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]>ans){
			ans=a[i];
			pos=i-1;
		}
	}
	printf("%d %d\n",ans,pos);
}
