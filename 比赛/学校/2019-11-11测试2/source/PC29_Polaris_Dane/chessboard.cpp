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
#define M 400000
#define N 50010
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
int n,k,m;
struct move{
	char id;
	int l1,r1,l2,r2;
	int	c;
	int wh;
}mo[M];
vector<int>loaded;
int nxt[M],a[1100][1100];
signed main(void){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	n=read(),k=read(),m=read();
	for (int i=1;i<=m;i++){
		char s[10];cin>>s;
		nxt[i]=i+1;
		mo[i].id=s[0];
		if (s[0]=='P'){
			mo[i].c=read();
			mo[i].l1=read(),mo[i].r1=read(),mo[i].l2=read(),mo[i].r2=read();
		}
		if (s[0]=='S')
			loaded.push_back(i);
		if (s[0]=='L')
			mo[i].wh=read(),nxt[loaded[mo[i].wh-1]]=i;
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			a[i][j]=1;
	for (int i=1;i<=m;i=nxt[i]){
		if (mo[i].id=='P'){
			for (int l=mo[i].l1;l<=mo[i].l2;l++)
				for (int r=mo[i].r1;r<=mo[i].r2;r++)
					a[l][r]=((l+r)&1)==((mo[i].l1+mo[i].r1)&1)?mo[i].c:a[l][r];
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		puts("");
	}
	return 0;
}

