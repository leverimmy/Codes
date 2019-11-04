#include <stdio.h>
#include <vector>
typedef long long TYPE;
const TYPE mod=99824353;
const int MAXN=1E5+10;
const int MAXC=256;
const int INF=~0U>>1;
int input() {
	int x=0,c=0;
	do c=getchar(); while(c<'0'||'9'<c);
	do x=x*10+c-'0',c=getchar(); while('0'<=c&&c<='9');
//	printf(">>>%d\n",x);
	return x;
}
int sinput() {
	int n=input();
	int x=0;
	for(int i=0;i<n;++i) {
		x|=(1<<input());
	}//printf(">>%d\n",x);
	return x;
}
bool belong(int x,int y) {
	return (x|y)==x;
}
TYPE powi(TYPE a,TYPE b) {
	TYPE ans=1;
	while(b) {
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;b>>=1;
	}return ans;
} 
TYPE syb(int z) {
	//printf(">>%d\n",z);
	return z%2==0 ? 1LL:-1LL;
}
int bits[MAXC],cnts[MAXC]; 
std::vector<int>bl[MAXC];
int pre[MAXN][MAXC];
TYPE js[MAXN],ij[MAXN];
void setup(const int N=1E5) {
	bits[0]=0; 
	for(int i=1;i<256;++i) {
		bits[i]=bits[i>>1]+i%2;
	}
	for(int i=0;i<256;++i) {
		for(int j=0;j<256;++j) {
			if(belong(i,j)) {
				bl[i].push_back(j);
				++cnts[i];
			}
		}
	}
	js[0]=1;
	for(int i=1;i<=N;++i) {
		js[i]=js[i-1]*i%mod;
	}
	ij[N]=powi(js[N],mod-2);
	for(int i=N-1;i>=0;--i) {
		ij[i]=ij[i+1]*(i+1)%mod;
	}
}
TYPE C(TYPE N,TYPE M) {
	return N<M ? 0 :js[N]*ij[N-M]%mod*ij[M]%mod;
}
TYPE count(int l,int r,int k,int x) {
	TYPE ans=0;
	int *p=pre[r];
	int *q=pre[l-1];
	for(int i=0;i<cnts[x];++i) {
		int y=bl[x][i];
		ans+=syb(bits[x]-bits[y])*C(p[y]-q[y],k);
		ans+=mod;ans%=mod;
	//	printf(">>%d\n",ans); 
	}return ans;
} 
int main() {
	freopen("picnic.in","r",stdin);
		freopen("picnic.out","w",stdout);
	setup();
	/*
	for(int i=1;i<=10;++i) {
		for(int j=1;j<=i;++j) {
			printf("%lld ",C(i,j));
		}printf("\n");
	}*/
	int n=input();
	int m=input();
	for(int i=1;i<=n;++i) {
		int x=sinput();
		for(int k=0;k<256;++k) {
			pre[i][k]=pre[i-1][k];
			if(belong(k,x))pre[i][k]++;
		}
	//	printf("%d\n",pre[i][x]);
	} 
	for(int i=1;i<=m;++i) {
		int l=input();
		int r=input();
		int k=input();
		int x=sinput();
		printf("%lld\n",count(l,r,k,x));
	}
	return 0;
}
