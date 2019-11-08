#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
char s[N],t[N];
int nxt[N];
void init(){
	int len=strlen(t+1);
	nxt[1]=1;
	for(int i=2,j=0; i<=len; i++){
		while(j!=0 && t[i]!=t[j+1]){
			j=nxt[j];
		}
		if(t[i]==t[j+1]){
			j++;
		}
		nxt[i]=j;
	}
}
bool work(){
	int len=strlen(s+1);
	int goal=strlen(t+1);
	for(int i=1,j=0; i<=len; i++){
		while(j!=0 && s[i]!=t[j+1]){
			j=nxt[j];
		}
		if(s[i]==t[j+1]){
			j++;
		}
		if(j==goal){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	while(scanf("%s%s",s+1,t+1)!=EOF){
		init();
		if(work()){
			puts("YES");
		}
		else {
			puts("NO");
		}
	}
	return 0;
}

