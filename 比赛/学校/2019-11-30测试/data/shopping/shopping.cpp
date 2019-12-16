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
ll f[MX][MX][2],ansc;
int c[MX],l[MX],ran[MX];
string s;
int n,nn;
bool flag[MX];
bool cmp(int x,int y){return c[x]==c[y]?l[x]<l[y]:c[x]>c[y];}
void scan()
{
	fin>>n>>s;
	if(n==0) {fout<<0;exit(0);}
	FOR(i,1,n) 
	{
		fin>>c[i]>>l[i];
		ran[i]=i;
	}
	sort(ran+1,ran+n+1,cmp);
	if(s[0]=='C') 
	{
		int t=ran[1];
		ansc=c[t];n--;
		FOR(i,1,n) ran[i]=ran[i+1];
		FOR(i,1,n) if(ran[i]>t) ran[i]--;
		FOR(i,t,n) 
		{
			l[i]=l[i+1];
			c[i]=c[i+1];
		}
	}
	nn=(n+1)>>1;
	//FOR(i,1,n) fout<<c[i]<<" ";fout<<endl;
	//FOR(i,1,n) fout<<l[i]<<" ";fout<<endl;
	//FOR(i,1,n) fout<<ran[i]<<" ";fout<<endl;
}
void work()
{
	FOR(i,1,n) FOR(j,1,(i+1)>>1)
	{
		if(j*2==i+1&&f[i-1][j-1][0]+l[ran[i]]>f[i-1][j][0]) 
		{
			f[i][j][0]=f[i-1][j-1][0]+l[ran[i]];
			f[i][j][1]=f[i-1][j-1][1];
		}
		else 
		{
			f[i][j][0]=f[i-1][j][0];
			f[i][j][1]=f[i-1][j][1]+c[ran[i]];
		}
	}
	fout<<f[n][nn][1]+ansc<<" "<<f[n][nn][0];
}
int main()
{
	fin.open("shopping1.in");
	fout.open("shopping.out");
	scan();
	work();
	return 0;
}