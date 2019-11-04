#include <cstdio>

using namespace std;

int n,k,t;
int p[1000010];

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		if(gcd(n,i)==1)
			p[++t]=i;
	}
	printf("%d",(k-1)/t*n+p[k%t]);
/*
	思路大概是这样的：
	裸的gcd肯定是不行的（TLE）
	我们可以这么找规律：
(ans)与8互质的数：				1	3	5	7	9	11	13	15	17	19 ....
(b)是第几个与8互质的数：	1	2	3	4	5	6	7	8	9	10
(c)除以8的余数：				1	3	5	7	1	3	5	7	1	3            有没有发现这一行在循环！
(d)除以8的商：					0	0	0	1	1	1	1	2	2	2
(e)减1后再除以8的值：			0	0	0	0	1	1	1	1	2	2			有没有发现变整齐了？
然后我们发现了这样一个规律：
!!!!!		ans=e*8+c	 !!!!!
这是n=8的规律，显然n=n时有ans=e*n+c
所以我们先把n以内与n互质的数存进p[]里面，顺便找到循环节t
然后就可以知道：
e=(k-1)/t
c=p[k%t]
带入上面的公式可以得到：
ans=(k-1)/t*n+p[k%t]
*/
	return 0;
}