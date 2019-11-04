#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

const int maxn=1000000;
int n,f;
int sum;
int cnt;
int ans;
int pd;
int p[maxn];
bool vis[maxn];

inline int read(){
	int w=1,x=0,ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return w*x;
}

int main(){
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	n=read(),f=read();
	for(register int i=1;i<=n;i++) p[i]=read();
	for(register int a=1;a<=n;a++){
		for(register int len=1;len<=n;len++){
			if((a+len*2+f-1)<=n){
				cnt=0;
				for(register int i=a;i<=(a+len-1);i++){
					for(register int j=(a+len+f);j<=(a+len*2+f-1);j++){
						if(p[i]==p[j]){
							cnt++;
							i++;
						}
					}
				}
				if(cnt==len) ans++;
			}
			else break;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
