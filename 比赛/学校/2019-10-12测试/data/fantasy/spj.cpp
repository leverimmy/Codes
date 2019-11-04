#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#define N 100010
#define OJ_AC 0
#define OJ_WA -1
using namespace std;
FILE *fstd,*fin,*fout,*fscore;
int n,m,A[N],B[N],C[N],du[N],wa=0;
char s[N];
int main(int argc,char *argv[])
{
	fin=fopen(argv[1],"r");///biaozhunshuru
	fout=fopen(argv[2],"r");//xuanshoushuchu
	fstd=fopen(argv[3],"r");//biaozhunshuchu
	fscore=fopen(argv[5],"w");
	fscanf(fin,"%d%d",&n,&m);
	int i,j;
	for(i=1;i<=m;i++) fscanf(fin,"%d%d%d",&A[i],&B[i],&C[i]);
	fscanf(fout,"%s",s+1);
	if(strlen(s+1)!=m)wa=1;
	for(i=1;i<=m;i++)
	{
		if(s[i]=='0') du[A[i]]++,du[B[i]]--;
		else if(s[i]=='1') du[A[i]]++,du[C[i]]--;
		else wa=1;
	}
	for(i=1;i<=n;i++)
	  if(du[i]!=0)wa=1;
    if(wa==0)
		fprintf(fscore,"%d",10);	
	else 
    	fprintf(fscore,"%d",0);

}
