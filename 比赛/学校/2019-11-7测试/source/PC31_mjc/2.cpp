#include<bits/stdc++.h>
using namespace std;

int n,r,m;
int vis[10];
int ans[1000];
int f[1000010][10]; 
char ch[10010];
int a,b,c,d;
int len;
int main(){
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",ch);
		len=strlen(ch);
		for(int j=0;j<len;j++){
			if(ch[j]=='A'){
				f[j+1][1]++;
			}
			if(ch[j]=='C'){
				f[j+1][2]++;
			}
			if(ch[j]=='G'){
				f[j+1][3]++;
			}
			if(ch[j]=='T'){
				f[j+1][4]++;
			}
		}
	}
	for(int i=1;i<=len;i++){
		int maxx=0,pos;
		for(int j=1;j<=4;j++){
			if(f[i][j]>maxx){
				maxx=f[i][j];
				pos=j;
			}
		}
		if(pos==1){
			printf("A");
		}
		if(pos==2){
			printf("C");
		}
		if(pos==3){
			printf("G");
		}
		if(pos==4){
			printf("T");
		}
	}
}
