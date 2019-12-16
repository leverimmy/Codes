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
const int MX=100010;
int x[MX],y[MX],f[MX];
int n,maxn,maxx;
bool cmp(int a,int b){return x[a]>x[b]&&y[a]>y[b];}
int main()
{
	fin.open("function1.in");
	fout.open("function.out");
	fin>>n;
	FOR(i,1,n) fin>>x[i]>>y[i];
	x[0]=y[0]=-inf;f[1]=1;
	FOR(i,2,n) FOR(j,0,i-1)
		if(cmp(i,j)) f[i]=max(f[i],f[j]+1);
    //FOR(i,1,n) fout<<f[i]<<" ";fout<<endl;
	FOR(i,1,n) maxn=max(f[i],maxn);
	fout<<maxn;
	return 0;
}
