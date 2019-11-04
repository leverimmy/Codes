#include<bits/stdc++.h>
using namespace std;
char tgt[4010],tmp[4010];
struct message
{
	char cont[1010];
	char name[1010];
	long long t,ctop;
}inpt[1010];
inline bool msgcmp(message qwq1,message qwq2)
{
	return qwq1.t<qwq2.t;
}
inline bool judge(int x)
{
	if(strlen(inpt[x].name)!=strlen(tgt))
		return false;
	for(int i=0;i<strlen(tgt);i++)
		if(tgt[i]!=inpt[x].name[i])
			return false;
	return true;
}
long long top,pw10[110];
int main()
{
	freopen("qqmessage.in","r",stdin);
	freopen("qqmessage.out","w",stdout);
	pw10[0]=1;
	for(int i=1;i<=16;i++)
		pw10[i]=pw10[i-1]*10;
	scanf("%s",tgt); 
	while(scanf("%s",tmp)!=-1)
	{
		top++;
		if(top%4==1)
		{
			if(strlen(tmp)!=10)
			{
				top--;
				goto gotozhenhaoyong_heihei;
			}
			for(int i=0;i<strlen(tmp);i++)
			{
				if(i!=4&&i!=7)
					if(isdigit(tmp[i])==false)
					{
						top--;
						goto gotozhenhaoyong_heihei;
					}
			}
			for(int i=0;i<4;i++)
				inpt[(top-1)/4+1].t+=pw10[13-i]*(tmp[i]-'0');
			for(int i=5;i<7;i++)
				inpt[(top-1)/4+1].t+=pw10[14-i]*(tmp[i]-'0');
			for(int i=8;i<10;i++)
				inpt[(top-1)/4+1].t+=pw10[15-i]*(tmp[i]-'0');
		}
		else if(top%4==2)
		{
			for(int i=0;i<2;i++)
				inpt[(top-1)/4+1].t+=pw10[5-i]*(tmp[i]-'0');
			for(int i=3;i<5;i++)
				inpt[(top-1)/4+1].t+=pw10[6-i]*(tmp[i]-'0');
			for(int i=6;i<8;i++)
				inpt[(top-1)/4+1].t+=pw10[7-i]*(tmp[i]-'0');
		}
		else if(top%4==3)
		{
			for(int i=0;i<strlen(tmp);i++)
				inpt[(top-1)/4+1].name[i]=tmp[i];
		}
		else if(top%4==0)
		{
			gotozhenhaoyong_heihei:
			int i=0;
			for(i=0;i<strlen(tmp);i++)
				inpt[(top-1)/4+1].cont[i+inpt[(top-1)/4+1].ctop]=tmp[i];
			inpt[(top-1)/4+1].ctop+=i;
			inpt[(top-1)/4+1].cont[inpt[(top-1)/4+1].ctop]=' ';
			inpt[(top-1)/4+1].ctop++;
		}
	}
	sort(inpt+1,inpt+(top/4)+1,msgcmp);
	top/=4;
	for(int i=1;i<=top;i++)
	{
		if(judge(i))
			cout<<inpt[i].cont<<endl;
	}
	return 0;
}
