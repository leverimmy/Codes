#include <bits/stdc++.h>
using namespace std;
const int o=100005;
char a1[o], b1[o];
int a[o],b[o],c[o],lena,lenb,lenc,i,x;
int main()
{
	freopen("12.in","r",stdin);
	freopen("12.out","w",stdout);
	while(scanf("%s",a1)!=EOF)
	{
	    memset(a,0,sizeof(a));
	    memset(b,0,sizeof(b));
	    memset(c,0,sizeof(c));
	    scanf("%s",b1);
	    lena=strlen(a1);
	    lenb=strlen(b1);
	    for(i=0;i<=lena-1;i++)
	        a[lena-i-1]=a1[i]-'0';
	    for(i=0;i<=lenb-1;i++)
	        b[lenb-i-1]=b1[i]-'0';
	    x=0;
	    for(i=0;i<=lena-1;i++)
	    {
	    	c[i]=a[i]-b[i]-x;
	    	if(c[i]<0)
	    		x=1,c[i]+=10;
	    	else
	    		x=0;
	    	++lenc;
		}
		while(c[lenc]==0&&lenc)
	        lenc--;
	    for(i=lenc;i>=0;--i)
	    	printf("%d",c[i]);
	    putchar(10);
	}
    return 0;
}
