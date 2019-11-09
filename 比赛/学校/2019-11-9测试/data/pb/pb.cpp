#include<cmath>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int inf=99999999;
const int MX=100010;
ifstream fin;
ofstream fout;
int u[110],p[110],c[110];
int f[110][110];
int n,w;
int main()
{
	fin.open("pb.in");
	fout.open("pb.out");
	fin>>n>>w;
	FOR(i,1,n) fin>>u[i];
	sort(u+1,u+n+1,greater<int>());
	FOR(i,1,n) c[i]=c[i-1]+u[i];
	//FOR(i,1,n) fout<<u[i]<<" ";fout<<endl;
	//FOR(i,1,n) fout<<c[i]<<" ";fout<<endl;
	if(w>n) w=n;
	FOR(i,1,n) FOR(j,0,n) f[i][j]=inf;
	f[0][0]=0;
	FOR(i,1,n) FOR(j,1,i) FOR(k,j-1,i)
		f[i][j]=min(f[i][j],f[k][j-1]+i*(c[i]-c[k]));
	double yi=1.00000;
	double ans=f[n][w]*yi/c[n];
	fout<<fixed<<setprecision(4)<<ans;
	return 0;
}

