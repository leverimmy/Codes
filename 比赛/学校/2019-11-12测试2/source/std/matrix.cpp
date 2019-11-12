#include<cstdio>
#include<iostream>
#define N 801
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)

using namespace std;
typedef long long llg;

int a[N][N],b[N][N],n,m;
llg ans;

int getint(){
	int w=0;bool q=0;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-') c=getchar();
	if(c=='-') c=getchar(),q=1;
	while(c>='0'&&c<='9') w=w*10+c-'0',c=getchar();
	return q?-w:w;
}

int main(){
	File("matrix");
	n=getint(); m=getint();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=getint()+a[i-1][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			b[i][j]=getint()+b[i][j-1];
	for(int i=1,x,y,X,Y;i<=m;i++){
		ans=0;
		x=getint(); y=getint();
		X=getint(); Y=getint();
		if(x>X) swap(x,X);
		if(y>Y) swap(y,Y);
		for(int j=1;j<=n;j++)
			ans+=(a[X][j]-a[x-1][j])*(b[j][Y]-b[j][y-1]);
		printf("%lld\n",ans);
	}
}
