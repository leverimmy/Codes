#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
int a,b;
int main(){
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	cin>>a>>b;
	int f=0;
	for(int i=a;i<=b;i+=5){
		if(!f) {
			for(int j=i;j<=min(i+4,b);j++) printf("%d ",j);
		}else {
			for(int j=min(i+4,b);j>=i;j--) printf("%d ",j);
		}
		f^=1;puts("");
	}
	return 0;
}
