#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
int a,b,m;
int main(){
	freopen("8.in","r",stdin);
	freopen("8.out","w",stdout);
	a=read(),b=read(),m=read();
	for(int x=1;x<=m;x++)
		for(int y=x;y<=m;y++) {
			if(a*x+b*y<=m){
				printf("%d,%d\n",x,y);
			}
		}
	return 0;
}
