#include<bits/stdc++.h>
using namespace std;

int n,f,fsq[100010];

int main(){
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	cin>>n>>f;
	for(int i=1;i<=n;i++){
		scanf("%d",&fsq[i]);
	}
	int ans=0;
	for(int a=1;a<=n;a++){
		for(int len=1;len<=n-a+1;len++){
			if(a+len*2+f-1>n) continue;
			for(int i=0;i<len;i++){
				if(fsq[a+i]!=fsq[a+len+f+i]) break;
				if(i==len-1) ans++;
			}
		}
	}
	cout<<ans;
}
