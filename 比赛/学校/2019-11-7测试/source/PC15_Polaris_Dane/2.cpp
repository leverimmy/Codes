#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdlib>
using namespace std;
const int M=202000;
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if (s=='-') f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x;
}
char s[M];
int cnt[110][27],maxx[110],pos[110];
signed main(void){
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int n=read();
	for (int i=1;i<=n;i++){
		cin>>s;
		for (int j=0;j<strlen(s);j++){
			cnt[j][s[j]-'A']++;
			if (maxx[j]<cnt[j][s[j]-'A']||(maxx[j]==cnt[j][s[j]-'A']&&pos[j]>s[j]-'A')){
				maxx[j]=cnt[j][s[j]-'A'];
				pos[j]=s[j]-'A';
			}
		}
	}
	for (int i=0;i<strlen(s);i++)
		putchar(pos[i]+'A');
	return 0;
}

