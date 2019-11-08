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
struct number{
	int num[10100],len;
	number(){
		memset(num,0,sizeof(num)),len=0;	
	}
	number operator *(const int&a)const{
		number c;
		int di=0;
		if (a<10) di=1;
		else if (a<100) di=2;
		else if (a<1000) di=3;
		else if (a<10000) di=4;
		else di=5;
		c.len=len+di;
		for (int i=1;i<=c.len;i++){
			c.num[i]=c.num[i]+num[i]*a;
			if (c.num[i]>9){
				if (i==c.len) c.len++;
				c.num[i+1]+=c.num[i]/10;
				c.num[i]%=10;
			}
		}
		return c;
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
}a,ans;
signed main(void){
	freopen("13.in","r",stdin);
	freopen("13.out","w",stdout);
	while (a.read()){
		int b=read();
		ans=a*b;
		ans.print();
	}
	return 0;
}
