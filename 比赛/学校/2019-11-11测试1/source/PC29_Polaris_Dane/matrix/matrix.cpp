#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cctype>
#include<set>
#define LL long long
#define M 400100
#define N 50010
#define int long long
using namespace std;
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int n,m;
int a[5100][5100],book[5100],ans;
signed main(void){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			char c;cin>>c;a[i][j]=c-'0',a[i][j]=a[i][j]?a[i][j-1]+1:0;
		}
	for (int i=1;i<=m;i++){
		memset(book,0,sizeof(book));
		for (int j=1;j<=n;j++)
			book[a[j][i]]++;
		for (int j=m;j>=1;j--)
			book[j]+=book[j+1];
		for (int j=1;j<=m;j++)
			ans=max(ans,book[j]*j);
	}
	printf("%d",ans);
	return 0;
}

