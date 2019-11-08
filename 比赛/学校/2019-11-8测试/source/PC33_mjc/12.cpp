#include<bits/stdc++.h>
using namespace std;
char s1[1000010];
char s2[1000010];
int a[1000010];
int b[1000010];
int c[1000010];
int main(){
	freopen("12.in","r",stdin);
	freopen("12.out","w",stdout);
	while(scanf("%s%s",s1,s2)!=EOF){
		int len1=strlen(s1);
		int len2=strlen(s2);
		for(int i=1;i<=len1;i++){
			a[i]=s1[i-1]-'0';
		}
		for(int i=1;i<=len2;i++){
			b[i]=s2[i-1]-'0';
		}
		reverse(a+1,a+len1+1);
		reverse(b+1,b+len2+1);
		memset(c,0,sizeof(c));
		for(int i=1;i<=len2;i++){
			c[i]+=a[i]-b[i];
			if(c[i]<0){
				c[i]+=10;
				c[i+1]--;
			}
		}
		for(int i=len2+1;i<=len1;i++){
			c[i]+=a[i];
		}
		int ed=0;
		if(c[len1+1]!=0){
			ed=len1+1;
		} 
		else{
			ed=len1;
		}
		reverse(c+1,c+ed+1);
		for(int i=1;i<=ed;i++){
			printf("%d",c[i]);
		}
		printf("\n");
	}
}
