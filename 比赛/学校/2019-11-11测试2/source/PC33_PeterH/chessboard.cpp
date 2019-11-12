#include<iostream>
#include<cstdio>
#include<cstdlib>
#define MAXn 102
using namespace std;
int n,m,k;
int a[3510][MAXn][MAXn],tot=1;
inline int read() {
	int sum=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) sum=(sum<<1)+(sum<<3)+(ch^'0'),ch=getchar();
	return sum*f;
}
void paint(int k,int xa,int ya,int xb,int yb) {
	int cnt=0;
	for(int i=xa; i<=xb; i++) {
		if(cnt%2==0) for(int j=ya; j<=yb; j+=2) a[tot][i][j]=k;
		else for(int j=ya+1; j<=yb; j+=2) a[tot][i][j]=k;
		cnt++;
	}
	return ;
}
int main() {
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	n=read(),k=read(),m=read();
	for(int i=0; i<=n-1; i++) for(int j=0; j<=n-1; j++) a[1][i][j]=1;
	for(int i=1; i<=m; i++) {
		string s;
		cin>>s;
		if(s=="PAINT") {
			int c=read(),x1=read(),y1=read(),x2=read(),y2=read();
			paint(c,x1,y1,x2,y2);
		} else if(s=="SAVE") {
			for(int i=0; i<=n-1; i++) for(int j=0; j<=n-1; j++) a[tot+1][i][j]=a[tot][i][j];
			tot++;
		} else {
			int x=read();
			for(int i=0; i<=n-1; i++) for(int j=0; j<=n-1; j++) a[1][i][j]=a[x][i][j];
			tot=1;
		}
	}
	for(int i=0; i<=n-1; i++) {
		for(int j=0; j<=n-1; j++)
			cout<<a[tot][i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
/*
3 4 7
PAINT 2 0 0 1 1
SAVE
PAINT 3 1 1 2 2
SAVE
PAINT 4 0 2 0 2
LOAD 2
PAINT 4 2 0 2 0
*/
