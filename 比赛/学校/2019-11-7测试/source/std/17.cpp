#include<iostream>
#include<cstdio>
using namespace std;

int n;
char x[1000],temp;

int Read()
{
	char x=getchar();int temp=0;bool f=0;
	while(x<'0'||x>'9')
	{
		if(x=='-')	f=1;
		x=getchar();
	}
	while(x>='0'&&x<='9')
	{
		temp=(temp<<3)+(temp<<1)+(x-'0');
		x=getchar();
	}
	return f ? -temp:temp;
}

int main()
{
	freopen("17.in","r",stdin);
	freopen("17.out","w",stdout);
	n=Read();
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i*2<=n;i++)
	{
		temp=x[i];x[i]=x[n+1-i];
		x[n+1-i]=temp;
		for(int j=1;j<=n;j++)	cout<<x[j];
		cout<<endl;
	}
	cout<<endl;
	for(int j=1;j<=n;j++)	cout<<x[j];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
