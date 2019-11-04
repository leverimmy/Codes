#include<bits/stdc++.h>
using namespace std;
namespace ProjectPolly
{
	const int mod=998244353;
	int quickpow(int x,int y)
	{
		long long res=1,base=x;
		while(y)
		{
			if(y&1) res*=base,res%=mod;
			y>>=1;base*=base,base%=mod;
		}
		return res;
	}
	int inv(int x){return quickpow(x,mod-2);}
	const int nttg=3;
	const int invg=inv(nttg);

	struct poly
	{
		vector<int>f;
		int &operator[](int x){return f[x];}
		const int &operator[](int x) const {return f[x];}
		void resize(int n){f.resize(n);}
		int size() const{return f.size();}
		void rev(){reverse(f.begin(),f.end());}
		void read(int n){f.resize(n);for(int i=0;i<n;++i)scanf("%d",&f[i]);}
		void out(){for(int i=0;i<f.size();++i)printf("%d ",f[i]);putchar('\n');}
	}R;
	int init(const int &n){int m;for(m=1;m<n;m<<=1);return m;}
	void rev(poly &f)
	{
		int n=f.size();
		R.resize(f.size());
		for(int i=0;i<n;++i)
			R[i]=(R[i>>1]>>1)|((i&1)?n>>1:0);
		for(int i=0;i<n;++i)
			if(i<R[i]) swap(f[i],f[R[i]]);
	}
	
	poly operator+(poly f,int c){f[0]=(f[0]+c)%mod;return f;}
	poly operator+(poly f,poly g){for(int i=0;i<f.size();i++)f[i]=(f[i]+((g.size()>i)?g[i]:0))%mod;return f;}
	poly operator-(poly f,poly g){for(int i=0;i<f.size();i++)f[i]=(f[i]-((g.size()>i)?g[i]:0)+mod)%mod;return f;}
	poly operator-(poly f){for(int i=0;i<f.size();i++)f[i]=mod-f[i];return f;}

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
					int tt=1ll*f[len+l]*buf%mod;
					f[len+l]=(f[l]-tt+mod)%mod;
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
	poly operator *(poly f,poly g)
	{
		int m=f.size()+g.size()-1;
		int n=init(m);
		f.resize(n);g.resize(n);
		NTT(f,1); NTT(g,1);
		for(int i=0;i<n;++i) f[i]=1ll*f[i]*g[i]%mod;
		NTT(f,-1);
		f.resize(m);
		return f;
	}
	poly operator*(poly f,int c){for(int i=0;i<f.size();++i) f[i]=1ll*f[i]*c%mod;return f;}
	poly Inv(const poly &f,int m)
	{
		if(m==1){poly g;g.resize(1);g[0]=inv(f[0]);return g;}
		poly g=Inv(f,(m+1)/2),t;
		int n=init(m*2);
		t.resize(n);g.resize(n);
		for(int i=0;i<m;++i) t[i]=f[i];
		NTT(g,1);NTT(t,1);
		for(int i=0;i<n;++i) g[i]=(2ll-1ll*g[i]*t[i]%mod+mod)*g[i]%mod;
		NTT(g,-1);
		g.resize(m);
		return g;
	}
	
	poly operator~(poly f){return Inv(f,f.size());}
	poly operator/(poly f,poly g){int len=f.size()-g.size()+1;f.rev();g.rev();g.resize(len);f=f*(~g);f.resize(len);f.rev();return f;}
	poly operator%(poly f,poly g){poly s=f/g;f=f-g*s;f.resize(g.size()-1);return f;}
	poly intergrate(poly f){int len=f.size();f.resize(len+1);for(int i=len;i>=1;--i){f[i]=1ll*f[i-1]*inv(i)%mod;}f[0]=0;return f;}
	poly diriviate(poly f){int len=f.size();for(int i=0;i<len-1;++i) f[i]=1ll*f[i+1]*(i+1)%mod;f.resize(len-1);return f;}
	poly Ln(poly f){poly g=diriviate(f),h=(~f);g=g*h;g.resize(f.size()-1);return intergrate(g);}
	poly Exp(const poly &f,int m)
	{
		if(m==1){poly g;g.resize(1);g[0]=1;return g;}
		poly g=Exp(f,(m+1)/2);
		g.resize(m);
		g=g*(-Ln(g)+f+1);
		g.resize(m);
		return g;
	}
	poly Exp(poly f){return Exp(f,f.size());}
	poly Pow(poly f,int x,int y)
	{
		poly g=Ln(f);
		g=g*x;g=g*inv(y);
		return Exp(g);
	}
}
using namespace ProjectPolly;
int invv[100001];
int main()
{
	freopen("fiorentina.in","r",stdin);
	freopen("fiorentina.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	poly f;
	f.resize(m+1);
	for(int i=1;i<=m;i++)
		invv[i]=inv(i);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m/i;j++)
		{
			if(j%2==1)
				f[i*j]=(f[i*j]+invv[j])%mod;
			else
				f[i*j]=(f[i*j]-invv[j]+mod)%mod;
		}
	}
	f=Exp(f);
	printf("%d",f[m]);
	return 0;
}
