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
		int k=a[i]-'0'-(b[i]-'0')+cf;
		cf=0;
		if(k<0){
			k+=10;
			cf=-1;
		}
		c[i]=k+'0';
	}
	int lenc=strlen(c);
	while(c[lenc]=='0'){
		lenc--;
	}
	for(int i=lenc-1; i>=0; i--){
		printf("%c",c[i]);
	}
	printf("\n");
}
int main(){
	freopen("12.in", "r", stdin);
	freopen("12.out", "w", stdout);
	while(scanf("%s%s",a,b)){
		add();
	}
	return 0;
}

