#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#include<cctype>
#include<stack>
#include<queue>
using namespace std;
const int M=200200;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
char s[10100];
int ans[1100000],anslen;
struct number{
	int num[1010],len;
	number(){
		memset(num,0,sizeof(num)),len=0;	
	}
	void operator *(const number&a)const{
		memset(ans,0,sizeof(ans));
		anslen=len+a.len;
		for (int i=1;i<=len;i++){
			for (int j=1;j<=a.len;j++){
				ans[i+j-1]+=num[i]*a.num[j];
				if (ans[i+j-1]>9) ans[i+j]+=ans[i+j-1]/10,ans[i+j-1]%=10;
			}
		}
	}
	void print(){
		int flag=1;
		for (int i=len;i>=1;i--)
			if (!num[i]&&flag) continue;
			else flag=0,printf("%d",num[i]);
		if (flag) printf("0");
		puts("");
	}
	bool read(){
		if (scanf("%s",s)==EOF) return 0;
		len=strlen(s);
		for (int i=strlen(s);i>=1;i--)
			num[len-i+1]=(s[i-1]^48);
		return 1;
	}
}a,b;
signed main(void){
	freopen("14.in","r",stdin);
	freopen("14.out","w",stdout);
	while (a.read()){
		b.read();
		int flag=1;
		a*b;
		for (int i=anslen;i>=1;i--)
			if (!ans[i]&&flag) continue;
			else flag=0,printf("%d",ans[i]);
		if (flag) printf("0");
		puts("");
	}
	return 0;
}
