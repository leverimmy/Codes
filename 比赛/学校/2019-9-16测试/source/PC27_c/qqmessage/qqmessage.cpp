#include <bits/stdc++.h>
using namespace std;

struct MES
{
	int year,month,day,hour,m,s;
	char mes[2000],user[2000];
};
MES qq[2005];
bool cmp(MES a,MES b)
{
	if(a.year==b.year){if(a.month==b.month){if(a.day==b.day){if(a.hour==b.hour){if(a.m==b.m){return a.s<b.s;}return a.m<b.m;}return a.hour<b.hour;}return a.day<b.day;}return a.month<b.month;}return a.year<b.year;
}
char now[1999];
char aaa[1999];
int _count;
int lenn;
char us[1005];
bool Check(MES a)
{
	int leen=strlen(a.user);
	if(leen!=lenn)
	{
		return false;
	}
	for(int i=1;i<=lenn;i++)
	{
		if(us[i-1]!=a.user[i-1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("qqmessage.in","r",stdin);
	freopen("qqmessage.out","w",stdout);
	scanf("%s",us);
	lenn=strlen(us);
	while(scanf("%s",now)!=EOF)
	{
		_count++;
		qq[_count].year=(now[0]-'0')*1000+(now[1]-'0')*100+(now[2]-'0')*10+(now[3]-'0');
		qq[_count].month=(now[5]-'0')*10+(now[6]-'0');
		qq[_count].day=(now[8]-'0')*10+(now[9]-'0');
		scanf("%s",now);
		qq[_count].hour=(now[0]-'0')*10+(now[1]-'0');
		qq[_count].m=(now[3]-'0')*10+(now[4]-'0');
		qq[_count].s=(now[6]-'0')*10+(now[7]-'0');
		int len=0;
		scanf("%s",now);
		len=strlen(now);
		for(int i=1;i<=len;i++)
		{
			qq[_count].user[i-1]=now[i-1];
		}
		len=strlen(qq[_count].user);
		gets(now);
		len=strlen(now);
		for(int i=1;i<=len;i++)
		{
			qq[_count].mes[i-1]=now[i-1];
		}
	}
	sort(qq+1,qq+_count+1,cmp);
//	for(int j=1;j<=_count;j++)
//	{
//		printf("%d-%d-%d %d:%d:%d ",qq[j].year,qq[j].month,qq[j].day,qq[j].hour,qq[j].m,qq[j].s);
//		int len=strlen(qq[j].user);
//		for(int i=0;i<=len;i++)
//		{
//			printf("%c",qq[j].user[i]);
//		}
//		len=strlen(qq[j].mes);
//		for(int i=1;i<=len;i++)
//		{
//			printf("%c",qq[j].mes[i]);
//		}
//		printf("\n");
//	}
	for(int j=1;j<=_count;j++)
	{
		if(Check(qq[j]))
		{
			int len=strlen(qq[j].mes);
			for(int i=1;i<=len-1;i++)
			{
				printf("%c",qq[j].mes[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
