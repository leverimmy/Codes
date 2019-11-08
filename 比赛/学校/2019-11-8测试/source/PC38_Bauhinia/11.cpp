#include <bits/stdc++.h>
using namespace std;
const int o=100005;
char a1[o], b1[o];
int a[o],b[o],c[o],lena,lenb,lenc,i,x;
int main()
{
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
	while(scanf("%s%s",a1,b1)!=EOF)
	{
	    memset(a,0,sizeof(a));
	    memset(b,0,sizeof(b));
	    memset(c,0,sizeof(c));
	    lena=strlen(a1);
	    lenb=strlen(b1);
	    for(i=0;i<=lena-1;i++)
	        a[lena-i]=a1[i]-'0';
	    for(i=0;i<=lenb-1;i++)
	        b[lenb-i]=b1[i]-'0';
	    x=0;
	    lenc=1;
	    while(lenc<=lena||lenc<=lenb)
	    {
	        c[lenc]=a[lenc]+b[lenc]+x;
	        x=c[lenc]/10;
	        c[lenc]%=10;
	        lenc++;
	    }
	    c[lenc]=x;
	    while(c[lenc]==0&&lenc!=1)
	        lenc--;
	    for(i=lenc;i>=1;i--)
	        printf("%d",c[i]);
	    putchar(10);
	}
    return 0;
}
