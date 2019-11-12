#include<bits/stdc++.h>

std::priority_queue<__int128, std::vector<__int128>, std::greater<__int128> > que;

signed main(void)
{
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    
    __int128 in; int inp;
    int totNums;

    scanf("%d", &totNums);
    for(int i=0;i<totNums;i++){
        scanf("%d", &inp); in = inp;
        que.push(in);
    }

    __int128 count=0,a,b;
    for(int i=1;i<totNums;i++){
        a = que.top(); que.pop(); b = que.top(); que.pop();
        count += a*b;
        que.push(a+b);
    }

    while(count>0){
        putchar(count%10+'0');
        count /= 10;
    } putchar('\n');

    //std::cout<<(double)clock()/CLOCKS_PER_SEC<<std::endl;
    
    return 0;
}
