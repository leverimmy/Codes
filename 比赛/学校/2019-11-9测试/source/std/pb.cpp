#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,w,tot,T;
int a[110];
double p[110],s[110];
double f[110][110];
int cmp(const int &a,const int &b){
	return a > b;
}
int main(){
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	scanf("%d%d",&n,&w);tot = 0;
	memset(f,0,sizeof(f));
	for (int i= 1;i<=n;i++) scanf("%d",&a[i]),tot+= a[i];
	sort(a+1,a+n+1,cmp);
	for (int i = 1;i<=n;i++)
		p[i] = ((double)a[i])/tot,s[i] = s[i-1] + p[i];
	for (int i = 1;i<=n;i++) f[i][1] = i*s[i];
	for (int i = 2;i<=n;i++)//哪一位
		for (int j = 2;j<=i;j++){//分几次
			f[i][j] = (1 << 30);
			for (int k = j;k<=i;k++)//从前面的哪一位
				f[i][j] = min(f[i][j],f[k-1][j-1] + i*(s[i]-s[k-1]));
		}
	printf("%.4lf\n",f[n][w]);	
	return 0;
}
