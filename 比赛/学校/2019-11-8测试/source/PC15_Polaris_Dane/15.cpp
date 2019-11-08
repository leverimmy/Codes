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
int b;
int di;
struct number{
	int num[10100],len;
	number(){
		memset(num,0,sizeof(num)),len=0;	
	}
	bool operator <(const number&a)const{
		if (len!=a.len) return len<a.len;
		for (int i=1;i<=len;i++)
			if (num[i]!=a.num[i]) return num[i]<a.num[i];
	}
	number operator -(const number&a)const{
		number c;
		c.len=max(len,a.len);
		for (int i=1;i<=c.len;i++){
			c.num[i]=c.num[i]+num[i]-a.num[i];
			if (c.num[i]<0){
				if (i==c.len) c.len--;
				c.num[i]+=10;
				c.num[i+1]-=1;	
			}
		}
		return c;
	}
	number operator /(const int&a)const{
		number c;
		for (int i=len;i>=di;i--){
			for (int j=1;j<=9;j++)
				
		}
	}
	void print(){
		for (int i=len;i>=1;i--)
			printf("%d",num[i]);
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
//	freopen("12.in","r",stdin);
//	freopen("12.out","w",stdout);
	while (a.read()){
		b=read();
		if (b<10) di=1;
		else if (b<100) di=2;
		else if (b<1000) di=3;
		else if (b<10000) di=4;
		else di=5;
		ans=a/b;
		ans.print();
	}
	return 0;
}
