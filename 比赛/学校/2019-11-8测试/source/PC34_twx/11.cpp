#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int N = 100010;
char a[N],b[N];
char c[N];
void add(){
	memset(c, 0, sizeof c);
	int lena=strlen(a),lenb=strlen(b);
	reverse(a, a+lena);
	reverse(b, b+lenb);
	int len=max(lena, lenb);
	int cf=0;
	for(int i=0; i<len; i++){
		int k=a[i]-'0'+b[i]-'0'+cf;
		cf=k/10;
		k%=10;
		c[i]=k+'0';
	}
	int lenc=strlen(c);
	c[(++lenc)-1]=cf+'0';
	while(c[lenc]=='0'){
		lenc--;
	}
	for(int i=lenc-1; i>=0; i--){
		printf("%c",c[i]);
	}
	printf("\n");
}
int main(){
	freopen("11.in", "r", stdin);
	freopen("11.out", "w", stdout);
	while(scanf("%s%s",a,b)){
		add();
	}
	return 0;
}

