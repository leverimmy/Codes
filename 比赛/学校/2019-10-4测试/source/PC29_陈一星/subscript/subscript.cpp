#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
#define M 1010000
#define inf 0x3f3f3f3f
#define LL long long
using namespace std;
const int mod=1e9+7;
int t;
string s;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){
		if(s=='-')f=-1;s=getchar();
	}
	while (isdigit(s))
	{
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*f;
}
inline bool comp(int a,int b,int c,int d){
	 for (int i=a;i<=b&&c+i-a<=d;i++){
	 	if (s[i]<s[c+i-a]) return true;
	 	if (s[i]>s[c+i-a]) return false;
	 }
	 return (b-a+1)<(d-c+1);
}
inline void calc(int l,int r){
	int out=0,pre=l,pree=l;
	for (int i=l;i<=r;i++){
		if (s[i]=='[') pree=pre,pre=i+1;
		if (s[i]==']') out=1;
		if (out) 
		{
			calc(pre,i-1),out=0;
			if (!comp(pree,pre-2,pre,i-1)){
				string t;
				t.append(s);
				for (int j=pre;j<=i-1;j++){
					s[j]=t[j-pre+pree];
				}
				for (int j=pree;j<=pre-2;j++){
					s[j]=t[j-pree+pre];
				}
			}
		}
	}
}
signed main(void)
{
//	freopen("subscript.in","r",stdin);
//	freopen("subscript.out","w",stdout);
	t=read();
	while (t--){
		cin>>s;
		calc(0,s.length()-1);
		cout<<s<<endl;
	}
    return 0;
}



