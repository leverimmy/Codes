#include<iostream>
#define MAXn 100002
using namespace std;
int n,m;
int a[MAXn];
inline int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
int main() {
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	n=read();
	m=read();
	for(int i=1; i<=n; i++) a[i]=read();
	while(m--) {
		int l,r,p,v,cnt=0;
		l=read();
		r=read();
		p=read();
		v=read();
		for(int i=l; i<=r; i++) if(a[i]%p==v) cnt++;
		cout<<cnt<<endl;
	}
	cout<<endl;
	return 0;
}
/*
5 2
1 5 2 3 7
1 3 2 1
2 5 3 0
*/
