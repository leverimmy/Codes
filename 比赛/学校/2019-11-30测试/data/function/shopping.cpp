#include<cmath>
#include<queue>
#include<cstdio>
#include<string>
#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define For(i,a,b) for(int i=a;i>=b;i++)
ifstream fin;
ofstream fout;
typedef long long ll;
const int inf=99999999;
const int MX=1010;
ll f[MX][MX][3];
int c[MX],l[MX],ran1[MX],maxn[MX][MX],cc[MX];
string s;
int m,n,p=0,nn,dis;
ll ansc,ansl;
bool flag[MX];
bool cmp1(int x,int y){return c[x]==c[y]?l[x]<l[y]:c[x]>c[y];}
bool cmp2(int x,int y){return l[x]==l[y]?c[x]<c[y]:l[x]>l[y];}
void scan()
{
	fin>>n>>s;
	FOR(i,1,n) 
	{
		fin>>c[i]>>l[i];
		ran1[i]=i;
	}
	sort(ran1+1,ran1+n+1,cmp1);
    FOR(i,1,n) fout<<ran1[i]<<" ";fout<<endl;
	if(s[0]=='C') 
	{
		int t=ran1[1];
		ansc+=c[t];n--;
		FOR(i,1,n) ran1[i]=ran1[i+1];
		FOR(i,t,n) 
		{
			l[i]=l[i+1];
			c[i]=c[i+1];
		}
	}
	FOR(i,1,n) cc[i]=l[ran1[i]];
	FOR(i,1,n) fout<<c[i]<<" ";fout<<endl;
	FOR(i,1,n) fout<<l[i]<<" ";fout<<endl;
	FOR(i,1,n) fout<<ran1[i]<<" ";fout<<endl;
	FOR(i,1,n) fout<<cc[i]<<" ";fout<<endl;
	nn=n/2;
	if(s[0]=='L'&&n%2==1) nn++;
	FOR(i,1,n) maxn[i][i]=i;
	FOR(j,2,n) FOR(i,1,n-j+1)
	if(cc[maxn[i][i+j/2-1]]>cc[maxn[i+j/2][i+j-1]]) maxn[i][i+j-1]=maxn[i][i+j/2-1];
	else maxn[i][i+j-1]=maxn[i+j/2][i+j-1];
	FOR(i,1,n) {FOR(j,1,n) fout<<cc[maxn[i][j]]<<" ";fout<<endl;}
}
void dg(int x,int y,int la)
{
	if(x==0&&y==0) return;
	//fout<<x<<" "<<y<<" "<<f[x][y][1]<<" "<<f[x][y][2]<<endl;
	FOR(i,f[x][y][1]+1,la) if(i!=f[x][y][2]) ansc+=c[ran1[i]];
	dg(f[x][y][1],y-1,f[x][y][1]);
}
void work()
{
	FOR(i,1,n)FOR(j,1,ceil(i*1.0/2)) FOR(k,(j-1)*2,i-1)
	if(f[k][j-1][0]+cc[maxn[k+1][i]]>f[i][j][0]) 
	{
		//fout<<i<<" "<<j<<" "<<k<<" "<<f[k][j-1][0]+cc[maxn[k+1][i]]<<endl;
		f[i][j][0]=f[k][j-1][0]+cc[maxn[k+1][i]];
		f[i][j][1]=k;
		f[i][j][2]=maxn[k+1][i];
	}
	ansl=f[n][nn][0];
	dg(n,nn,n);
	fout<<ansc<<" "<<ansl;
}
int main()
{
	fin.open("shopping.in");
	fout.open("shopping.out");
	scan();
	work();
	return 0;
}







