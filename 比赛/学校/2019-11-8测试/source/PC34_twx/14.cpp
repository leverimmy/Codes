#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1010;
char a[N],b[N];
int c[N];
void add(){
	memset(c, 0, sizeof c);
	int lena=strlen(a),lenb=strlen(b);
	reverse(a, a+lena);
	reverse(b, b+lenb);
	for(int i=0; i<lenb; i++){
		for(int j=0; j<lena; j++){
			c[j+i]+=(b[i]-'0')*(a[j]-'0');
			c[j+i+1]+=c[j+i]/10;
			c[j+i]%=10;
		}
	}
	int now=lena;
	while(c[now]!=0){
		now++;
	}
	for(int i=0; i<now; i++){
		if(c[i]>10){
			c[i+1]+=c[i]/10;
			c[i]%=10;
			if(i+1>now){
				now=i+1;
			}
		}
	}
	for(int i=now-1; i>=0; i--){
		printf("%d",c[i]);
	}
	printf("\n");
}
int main(){
	freopen("14.in", "r", stdin);
	freopen("14.out", "w", stdout);
	while(scanf("%s%s",a,b)){
		add();
	}
	return 0;
}

