#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ran(int x)
{
	return ((rand()<<15)+rand())%x+1;
}
string ranit(){string ret="";ret+=(ran(26)+96);ret+=(ran(26)+96);ret+=(ran(26)+96);ret+=(ran(26)+96);return ret;}
string S[100010];
int main()
{
	srand(time(0));
	freopen("liverpool8.in","w",stdout);
	int n=456976+1,m=100;
	int i,j,k,l,x,y;
	printf("%d\n",n);
	for(i=1;i<=26;i++)for(j=1;j<=26;j++)for(k=1;k<=26;k++)for(l=1;l<=26;l++)
	{
		cout<<(char)(i+96)<<char(j+96)<<char(k+96)<<char(l+96)<<' ';
		if(j==1) cout<<0<<endl;
		else cout<<ran(1000)<<endl; 
	}
	cout<<"aaaaaaaaaaaaaaaa"<<' '<<0<<endl;
	printf("%d\n",m);
	int re=40000;
	for(i=1;i<=m-2;i++)
	{
		x=ran(re-(m-i));
		printf("%d",x);
		while(x--)
		cout<<' '<<ranit();
		puts("");
		re-=x;
	}
	for(i=1;i<=2;i++)
	{
		x=ran(re-(m-i));
		printf("%d",x);
		while(x--)
		cout<<' '<<ranit();
		puts("");
	}
	
/*	cout<<"2 a "<<"aaaa"<<endl;
	cout<<"2 "<<"aaaa"<<" a"<<endl;*/
	
}