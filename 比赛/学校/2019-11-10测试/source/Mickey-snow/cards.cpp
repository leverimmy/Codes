#include<bits/stdc++.h>

signed main(void)
{
#define sqr(x) ((x)*(x))

    freopen("cards.in","r",stdin);
    freopen("cards.out","w",stdout);
    
    long long a,b;

    std::cin>>a>>b;
    if(a>=b){
        std::cout<<sqr(a)-sqr(b)<<std::endl;
        while(a--) putchar('o');
        while(b--) putchar('x');
    }
    else std::cout<<"Revolution of our time."<<std::endl;
    
    return 0;
}
