#include <bits/stdc++.h>
using namespace std;
char a[15][105];
int main()
{
	
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%s",a[i]);
	}
	int len=strlen(a[1]);
	for(int i=0;i<len;i++)
	{
		int A=0,G=0,C=0,T=0;
		for(int j=1;j<=N;j++)
		{
			if(a[j][i]=='A')
			{
				A++;
			}
			if(a[j][i]=='G')
			{
				G++;
			}
			if(a[j][i]=='T')
			{
				T++;
			}
			if(a[j][i]=='C')
			{
				C++;
			}
		}
		if(A>=G&&A>=T&&A>=C)
		{
			printf("A");
		}
		else if(C>=A&&C>=G&&C>=T)
		{
			printf("C");
		}
		else if(G>=A&&G>=C&&G>=T)
		{
			printf("G");
		}
		else if(T>=A&&T>=C&&T>=G)
		{
			printf("T");
		}
	}
	return 0;
}

