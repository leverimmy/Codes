#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int read(){
	int f=1,ans=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
int f[3][1010];
map<int,int> back;
int to[1010];
int cnt;
int m1,m2,n;
int a[500010];
int b[500010];
int c[500010];
int d[500010];
int main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	n=read();m2=read();m1=read();
	for(int i=1;i<=n;i++){
		c[i]=read(); 
		d[i]=c[i];
	}	
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		if(!back[c[i]]){
			to[++cnt]=c[i];
			back[c[i]]=cnt;
		}
	}
	for(int i=1;i<=n;i++){
		a[i]=back[d[i]];
		b[n-i+1]=a[i];
	}
	for(int i=0;i<=cnt;i++){
		f[0][i]=inf;
		f[1][i]=inf;
	}
	for(int i=1;i<=cnt;i++){
		if(a[1]<=i) f[1][i]=0;
//		if(a[1]<i){
//			f[1][i]=m1;
//		}
		if(a[1]>i){
			f[1][i]=m2;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			if(a[i]>j)
				f[i%2][j]=min(f[(i-1)%2][j]+m1,f[i%2][j-1]);
			if(a[i]==j)
				f[i%2][j]=min(f[(i-1)%2][j],f[i%2][j-1]);
			if(a[i]<j)
				f[i%2][j]=min(f[(i-1)%2][j]+m2,f[i%2][j-1]);
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<=cnt;i++){
		ans=min(ans,f[n%2][i]);
	}	
	
	
	for(int i=0;i<=cnt;i++){
		f[0][i]=inf;
		f[1][i]=inf;
	}
	for(int i=1;i<=cnt;i++){
		if(b[1]<=i) f[1][i]=0;
//		if(a[1]<i){
//			f[1][i]=m1;
//		}
		if(b[1]>i){
			f[1][i]=m2;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			if(b[i]>j)
				f[i%2][j]=min(f[(i-1)%2][j]+m1,f[i%2][j-1]);
			if(b[i]==j)
				f[i%2][j]=min(f[(i-1)%2][j],f[i%2][j-1]);
			if(b[i]<j)
				f[i%2][j]=min(f[(i-1)%2][j]+m2,f[i%2][j-1]);
		}
	}
	
	for(int i=1;i<=cnt;i++){
		ans=min(ans,f[n%2][i]);
	}
	printf("%d\n",ans);
}
