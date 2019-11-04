#include <bits/stdc++.h>
#define ft(i,a,b) for(int i=(a); i<=(b); ++i)
#define fd(i,a,b) for(int i=(a); i>=(b); --i)
#define fv(i,v) for(size_t i=0; i<(v).size(); ++i)
#define PB push_back
#define MP make_pair
#define F first
#define S second
using namespace std;

const int N=1050, P=998244353;

int f[N][11],mx;
int a[11];

void add(int x){
	fd(i,mx,0) ft(j,0,10) (f[i+1][(j+x)%11]+=f[i][j])%=P;
	a[x]++; mx++;
}

void del(int x){
	ft(i,0,mx) ft(j,0,10) (f[i+1][(j+x)%11]+=P-f[i][j])%=P;
	a[x]--; mx--;
}

char s[N];

int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	f[0][0]=1;
	ft(i,1,n) add(s[i]-'0');
	
	int sum=0;
	ft(i,1,n) (sum+=s[i]-'0')%=11;
	int half=sum*6%11;
	if (f[n/2][half]==0){
		printf("-1\n");
		return 0;
	}
	
	int s0=half, s1=half;
	
	ft(i,1,n){
		//printf("%d %d %d\n",i,s0,s1);
		int aa,bb;
		if (i&1) { aa=n/2-i/2; bb=s0; }
			else { aa=(n+1)/2-(i+1)/2; bb=s1; }
		
		int x=9;
		while (true){
			if (!a[x]){
				x--; continue;
			}
			del(x);
			//if ((i&1) && f[n/2-i/2][s0]) break;
			//if (!(i&1) && f[(n+1)/2-(i+1)/2][s1]) break;
			if (f[aa][bb]) break;
			add(x);
			x--;
		}
		if (i&1) (s1+=(11-x))%=11;
			else (s0+=(11-x))%=11;
			
		//printf("%d %d %d\n",i,s0,s1);
		//printf("x==%d\n",x);	
		putchar('0'+x);
	}
	putchar('\n');
	return 0;
}