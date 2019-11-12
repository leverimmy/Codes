#include<bits/stdc++.h>
using namespace std;
char s[100001];
signed main()
{
	//freopen("tea.in","r",stdin);
	//freopen("tea.out","w",stdout);
	int T,sum=0;
	scanf("%d",&T);
	while(T--)
	{
		cin>>s+1;
		int n=strlen(s+1);
		int tot=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='E'||s[i]=='Q'||s[i]=='W'||s[i]=='R'||s[i]=='e'||s[i]=='q'||s[i]=='w'||s[i]=='r')
				tot++;
		if(tot>n/2)
			sum++;
	}
	printf("%d\n",sum);
	return 0;
}
