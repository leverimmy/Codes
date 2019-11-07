#include<cstdio>
#include<cstring>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
int num[13],S[13];
int trs(ll x)
{
	int p(0);
	while(x)
	{
		num[++p]=(int)(x%10ll);
		x/=10ll;
	}
	return p;
}
std::string str[10]={"ling ","yi ","er ","san ","si ","wu ","liu ","qi ","ba ","jiu "};
std::string wei[6]={"","shi ","bai ","qian ","wan ","yi "};
signed main()
{
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	int m=trs(n);
	if(m==1)
	{
		std::cout<<str[num[1]];
		return puts(""),0;
	}
	for(int i=1;i<=12;i++)
		S[i]=S[i-1]+num[i];
	for(int i=m;i>=1;i--)
	{
		if(!num[i])
			while(!num[i-1]&&i-1)
			{
				if(i==9||i==5)
				{
					if(i==9&&S[12]-S[8])
						printf("yi ");
					if(i==5&&S[8]-S[4])
						printf("wan ");
				}
				i--;
			}
		if((num[i]!=1||!num[i+1]||i==2||i==6||i==10)&&i!=1&&i!=m)
			std::cout<<str[num[i]];
		if(i==m&&(num[i]>1||(i!=2&&i!=6&&i!=10)))
			std::cout<<str[num[i]];
		if(i==1&&num[i])
			std::cout<<str[num[i]];
		if(num[i])
		{
			if(i==12)
				std::cout<<wei[3];
			if(i==11)
				std::cout<<wei[2];
			if(i==10)
				std::cout<<wei[1];
			if(i==9)
				std::cout<<wei[5];
			if(i==8)
				std::cout<<wei[3];
			if(i==7)
				std::cout<<wei[2];
			if(i==6)
				std::cout<<wei[1];
			if(i==5)
				std::cout<<wei[4];
			if(i==4)
				std::cout<<wei[3];
			if(i==3)
				std::cout<<wei[2];
			if(i==2)
				std::cout<<wei[1];
		}
	}
	return puts(""),0;
}
