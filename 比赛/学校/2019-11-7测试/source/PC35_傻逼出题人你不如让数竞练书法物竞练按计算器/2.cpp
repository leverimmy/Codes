#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[15][105];
int num[105][15],mp[305];
char kon[]={'0','A','C','G','T'};
int main(){
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout); 
	cin>>n;
	mp['A']=1,mp['C']=2,mp['G']=3,mp['T']=4;
	for(int i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
		m=strlen(s[i]+1);
		for(int j=1;j<=m;j++) num[j][mp[s[i][j]]]++;
	}
	for(int i=1;i<=m;i++){
		int mx=*max_element(num[i]+1,num[i]+5);
		for(int j=1;j<=4;j++) {
			if(num[i][j]==mx) {
				putchar(kon[j]);
				break;
			}
		}
	}
	return 0;
}
