#include<cstdio>
#include<cstring>
#define ri register int
inline int read(){
	ri x=0;register char ch=getchar();
	while(ch>'9' || ch<'0')ch=getchar();
	while(ch<='9' && ch>='0')
		x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
int a[20],b[10],n,t;
bool f[20][10000],vis[20][10000];
/*inline bool dfs(ri m,ri num){
 	if(num==1){
		return f[m][num]=(m+1)%2;
	}
	if(vis[m][num])return f[m][num];
	bool flag;
	if(m%2){
		flag=false;for(ri i=1;i<=a[m] && i<num && !flag;++i)
		flag|=dfs(m%t+1,num-i);
	}
	else{
		flag=true;for(ri i=1;i<=a[m] && i<num && flag;++i)
		flag&=dfs(m%t+1,num-i);
	}
	vis[m][num]=true;
	return f[m][num]=flag;
}*/
int main(){
	freopen("game.in","r",stdin),freopen("game.out","w",stdout);
	n=read();
	while(n){
		ri s=read(),sum=0;t=n<<1;
		for(ri i=1;i<=t;++i)a[i]=read();
		for(ri i=1;i<=t;++i)f[i][1]=(i+1)%2;
		for(ri i=2;i<=s;++i)for(ri j=1;j<=t;++j)
				if(j%2){f[j][i]=false;
					for(ri k=1;k<=a[j] && k<i && !f[j][i];++k)
					f[j][i]|=f[j%t+1][i-k];}
				else{f[j][i]=true;
					for(ri k=1;k<=a[j] && k<i && f[j][i];++k)
					f[j][i]&=f[j%t+1][i-k];}
		puts(f[1][s]?"1":"0");
		n=read();
	}
	return 0;
} 
