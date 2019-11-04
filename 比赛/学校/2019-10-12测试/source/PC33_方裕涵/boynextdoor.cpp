#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int T;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
int main() {
	freopen("boynextdoor.in","r",stdin);
	freopen("boynextdoor.out","w",stdout);
	T=read();
	while(T--) {
		int a,b;
		a=read();
		b=read();
		if(a!=0&&b!=0) cout<<a-b-2<<endl;
		else cout<<a-b<<endl;
	}
	return 0;
}
