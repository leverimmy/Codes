#include <bits/stdc++.h>
using namespace std;

int read()
{
	int res=0,p=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')p=-1; ch=getchar();}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*p;
}

int t,cnt,num,f[1000],fl,ob[1001];

char b[10000][500];

void getstring()
{
	char ch=getchar();
	while(ch<'a' || ch>'z') ch=getchar();
	while((ch>='a' && ch<='z') || ch=='[' || ch==']')
	{
		if(ch=='[') num=0,cnt++,fl++,ch=getchar();
		else if(ch==']') fl--,ch=getchar();
		else b[cnt][++num]=ch,f[cnt]=fl,ch=getchar();
	}
}

void putstr(int a)
{
	for(int i=1;b[a][i]!=' ';i++)
		cout << b[a][i];
}

int minstr(int x,int y)
{
	if(strcmp(b[x],b[y])<0) return x;
	return y;	
}

int maxstr(int x,int y)
{
	if(strcmp(b[x],b[y])>0) return x;
	return y;
}

int main()
{
	freopen("subscript.in","r",stdin);
	freopen("subscript.out","w",stdout);
	t=read();
	for(int test=1;test<=t;test++)
	{
		cnt=1,num=0,fl=1;
		memset(b,' ',sizeof(b));
		memset(ob,0,sizeof(ob));
		getstring();
		if(cnt==1)
		{
			putstr(1);
			cout << endl;
			continue;
		}
		if(cnt==2)
		{
			if(strcmp(b[1],b[2])<0)
			{
				putstr(1);cout << "[";putstr(2);cout << "]" << endl;
				continue;
			}
			else
			{
				putstr(2);cout << "[";putstr(1);cout << "]" << endl;
				continue;
			}
		}
		if(cnt==3)
		{
			if(f[3]==2)
			{
				ob[1]=minstr(1,2);
				ob[1]=minstr(ob[1],3);
				ob[3]=maxstr(1,2);
				ob[3]=maxstr(ob[3],3);
				if(ob[1]==1) if(ob[3]==2)
					ob[2]=3;
				else
					ob[2]=2;
				if(ob[1]==2) if(ob[3]==1)
					ob[2]=3;
				else
					ob[2]=1;
				if(ob[1]==3) if(ob[3]==1)
					ob[2]=2;
				else
					ob[2]=1;
				putstr(ob[1]);cout << "[";putstr(ob[2]);cout << "][";putstr(ob[3]);cout << "]" << endl;
			}
			if(f[3]==3)
			{
				ob[2]=minstr(2,3);
				ob[3]=maxstr(2,3);
				if(strcmp(b[1],b[ob[2]])<0) putstr(1),cout << "[",putstr(ob[2]),cout<<"[",putstr(ob[3]),cout<<"]]"<<endl;
				else putstr(ob[2]),cout << "[",putstr(ob[3]),cout<<"][",putstr(1),cout<<"]"<<endl;
			}
			continue;
		}
		putstr(1);
		for(int i=2;i<=cnt;i++) cout<<"[",putstr(i),cout<<"]";
		cout << endl;
	}
	return 0;
}

