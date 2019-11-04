#include <stdlib.h>
#include <stdio.h>
long long int n,i,a1,a2,as,b1,b2,bs,c1,c2,cs,ans;
int main()
{
    scanf("%lld",&n);
    scanf("%lld %lld\n %lld %lld\n %lld %lld",&a1,&a2,&b1,&b2,&c1,&c2);
    if(n%a1==0) as=n/a1*a2; else as=(n/a1+1)*a2;     
    if(n%b1==0) bs=n/b1*b2; else bs=(n/b1+1)*b2;
    if(n%c1==0) cs=n/c1*c2; else cs=(n/c1+1)*c2;
    if(as<bs && as<cs) ans=as;    
    if(bs<as && bs<cs) ans=bs;
    if(cs<as && cs<bs) ans=cs;
    printf("%lld",ans);
    //system("pause");
    return 0;
}
