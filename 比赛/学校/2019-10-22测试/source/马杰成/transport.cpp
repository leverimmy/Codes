	#include<bits/stdc++.h>
using namespace std;
int f[505][505];
struct node{
	int x;
	int y;
}in[550];
int n,k;
int cal(int i,int j){
	return abs(in[i].x-in[j].x)+abs(in[i].y-in[j].y);
}
int main(){	
	freopen("transport.in","r",stdin);
	freopen("transport.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&in[i].x,&in[i].y);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			f[i][j]=0x3f3f3f3f;
		}
	}
	f[1][0]=0; 
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			for(int l=1;l<i;l++){
				if((j-(i-l-1))>=0)
					f[i][j]=min(f[i][j],f[l][j-(i-l-1)]+cal(l,i));
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=k;j++){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<=k;i++){
		ans=min(ans,f[n][i]);
	}
	printf("%d\n",ans);
}
