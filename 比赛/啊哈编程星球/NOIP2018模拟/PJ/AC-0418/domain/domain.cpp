#include <cstdio>
#include <cstring>
#define prime 131
#define MOD 19260817
#define base 998244353
using namespace std;

int n,cnt,len_wanted,len_interested;
char wanted[110],interested[110];
int book[19260819],power[110];

void init()
{
	power[0]=19260813;
	for(int i=1;i<=100;i++)
		power[i]=(unsigned long long)((power[i-1]%MOD)*(base%MOD))%MOD;
}

void print()
{	
	if(cnt==0)
		printf("NO");
	else if(cnt==n)
		printf("ALL");
	else
		printf("%d",cnt);
}

void get_wanted()
{
	int cnt_dot=0;
	for(int i=0;i<len_interested;i++)
	{
		if(cnt_dot>=1)
			wanted[len_wanted++]=interested[i];
		if(interested[i]=='.')
			cnt_dot++;
	}
}

int hash(char s[],int len)
{
	long long ans=0;
	for(int i=0;i<len;i++)
		ans+=((unsigned long long)((s[i]-'a')*power[i]+prime))%MOD;
	return ans%MOD;
}

int main()
{
	init();
	freopen("domain.in","r",stdin);
	freopen("domain.out","w",stdout);
	scanf("%s",interested);
	scanf("%d",&n);
	len_interested=strlen(interested);
	get_wanted();
	//puts(wanted);
	for(int i=1;i<=n;i++)
	{
		int len=len_wanted;
		int len_domain,flag=1;
		char domain[110];
		scanf("%s",domain);
		len_domain=strlen(domain);
		int h=hash(domain,len_domain);
		if(strcmp(interested,domain)==0 || book[h]==1)
			continue;
		book[h]=1;
		len--;
		for(int j=len_domain-1;len>=0;j--)
			if(wanted[len--]!=domain[j])
			{
				flag=0;
				break;
			}
		cnt+=flag;
	}
	print();
	return 0;
}