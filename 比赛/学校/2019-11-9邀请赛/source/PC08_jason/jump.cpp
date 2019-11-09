#include<bits/stdc++.h>
using namespace std;
namespace ProjectPollyJr
{
	const int mod=998244353;
	int quickpow(int x,int y)
	{
		long long res=1,base=x;
		while(y)
		{
			if(y&1) res*=base,res%=mod;
			y>>=1; base*=base,base%=mod;
		}
		return res;
	}
	int inv(int x){return quickpow(x,mod-2);}
	const int nttg=3;
	const int invg=inv(nttg);
	struct poly
	{
		vector<int>f;
		int &operator[](int n){return f[n];}
		const int &operator[](int n)const{return f[n];}
		void resize(int n){f.resize(n);}
		int size()const{return f.size();}
		void rev(){reverse(f.begin(),f.end());}
		void read(int n){f.resize(n);for(int i=0;i<n;i++)scanf("%d",&f[i]);}
		void out(){for(int i=0;i<f.size();i++)printf("%d ",f[i]);printf("\n");}
		void cpy(poly g,int c){for(int i=0;i<c;i++)f[i]=g[i];}
	}R;
	int init(int m){int n=1;for(;n<m;n<<=1);return n;}
	void rev(poly &f)
	{
		int n=f.size();
		R.resize(n);
		for(int i=0;i<n;i++)
			R[i]=(R[i>>1]>>1)|((i&1)?n>>1:0);
		for(int i=0;i<n;i++)
			if(i<R[i]) swap(f[i],f[R[i]]);
	}
	poly operator+(poly f,int c){f[0]=(f[0]+c)%mod;return f;}
	poly operator+(poly f,poly g){for(int i=0;i<f.size();i++)f[i]=(f[i]+((i<g.size())?g[i]:0))%mod;return f;}
	poly operator-(poly f,poly g){for(int i=0;i<f.size();i++)f[i]=(f[i]-((i<g.size())?g[i]:0)+mod)%mod;return f;}
	poly operator*(poly f,int c){for(int i=0;i<f.size();i++)f[i]=1ll*f[i]*c%mod;return f;}
	void NTT(poly &f,int op)
	{
		int n=f.size();rev(f);
		for(int w=2;w<=n;w<<=1)
		{
			int len=w/2;
			int tmp=quickpow((op==1)?nttg:invg,(mod-1)/w);
			for(int k=0;k<n;k+=w)
			{
				int buf=1;
				for(int l=k;l<k+len;l++)
				{
					int tt=1ll*f[l+len]*buf%mod;
					f[l+len]=(f[l]-tt+mod)%mod;
					f[l]=(f[l]+tt)%mod;
					buf=1ll*buf*tmp%mod;
				}
			}
		}
		if(op==-1)
		{
			int invn=inv(n);
			for(int i=0;i<n;i++) f[i]=1ll*f[i]*invn%mod;
		}
	}
	poly operator*(poly f,poly g)
	{
		int m=f.size()+g.size()-1;
		int n=init(m);
		f.resize(n);g.resize(n);
		NTT(f,1);NTT(g,1);
		for(int i=0;i<n;i++)f[i]=1ll*f[i]*g[i]%mod;
		NTT(f,-1);
		f.resize(m);
		return f;
	}
}
using namespace ProjectPollyJr;

int n,k;
vector<int>e[100001];
long long sum[100001];
poly f[100001];
int siz[100001];
long long ans=0;
void dfs(int u,int fa)
{
	if(u!=1)e[u].erase(lower_bound(e[u].begin(),e[u].end(),fa));
	if(e[u].size()==0)
	{
		siz[u]=1;
		f[u].resize(k+1);
		f[u][0]=1;
		return;
	}
	dfs(e[u][0],u);
	f[u]=f[e[u][0]];
	sum[u]=sum[e[u][0]];
	f[u].f.insert(f[u].f.begin(),0);
	
	sum[u]+=f[u][k];
	f[u][0]+=f[u][k];
	f[u].resize(k);
	
	for(int i=1;i<e[u].size();i++)
	{
		int to=e[u][i];
		if(to!=fa)
		{
			dfs(to,u);
			f[to].f.insert(f[to].f.begin(),0);
			
			sum[to]+=f[to][k];
			f[to][0]+=f[to][k];
			f[to].resize(k);

			ans+=sum[u]*siz[to];
			ans+=sum[to]*siz[u];
			
			sum[u]+=sum[to];
			poly tmp=f[u]*f[to];
			
			for(int j=1;j<=k;j++)
				ans+=tmp[j];
			for(int j=k+1;j<=2*k-2;j++)
				ans+=2*tmp[j];
			
			f[u]=f[u]+f[to];
			
			siz[u]+=siz[to];
		}
	}
	ans+=sum[u];
	for(int i=1;i<k;i++)
		ans+=f[u][i];	
	f[u][0]++;
}
signed main() 
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		sort(e[i].begin(),e[i].end());
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
