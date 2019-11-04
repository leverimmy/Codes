#include<cstdio>
#define maxn 100005
#define re register
using namespace std;

inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*f;
}

bool flag;

int n,f,ans;

int power[maxn];

int main()
{
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	n=read();
	f=read();
	for(re int i=1;i<=n;++i){
		power[i]=read();
	}
	for(re int a=1;a<=n;++a){
		for(re int len=1;len<=n;++len){
			if(a+len*2+f-1<=n){
			//	ans1++;
				flag=1;
				for(re int i=0;i<len;++i){
					if(power[a+i]!=power[a+len+f+i]){
						flag=0;
						break;
					}	
				}
				if(flag==1){
					ans++;
				//	printf("a=%d len=%d\n",a,len);
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

/*
11 4
1 1 1 4 1 -8 1 1 1 4 1
*/
// 6
