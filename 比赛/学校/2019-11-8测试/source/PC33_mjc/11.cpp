#include<bits/stdc++.h>
using namespace std;
char s1[1000010];
char s2[1000010];
int a[1000010];
int b[1000010];
int c[1000010];
int main(){
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
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
		if(len1<len2){
			for(int i=1;i<=len1;i++){
				c[i+1]+=(a[i]+b[i])/10; 
				c[i]+=(a[i]+b[i])%10;
			}
			for(int i=len1+1;i<=len2;i++){
				c[i]+=b[i];
			}
			int ed=0;
			if(c[len2+1]!=0){
				ed=len2+1;
			} 
			else{
				ed=len2;
			}
			reverse(c+1,c+ed+1);
			for(int i=1;i<=ed;i++){
				printf("%d",c[i]);
			}
			printf("\n");
		}
		if(len2<len1){
			for(int i=1;i<=len2;i++){
				c[i+1]+=(a[i]+b[i])/10; 
				c[i]+=(a[i]+b[i])%10;
			}
			for(int i=len2+1;i<=len1;i++){
				c[i]+=b[i];
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
		if(len1==len2){
			for(int i=1;i<=len2;i++){
				c[i+1]+=(a[i]+b[i])/10; 
				c[i]+=(a[i]+b[i])%10;
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
}
