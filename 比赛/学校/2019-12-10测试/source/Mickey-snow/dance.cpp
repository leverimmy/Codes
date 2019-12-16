#include<bits/stdc++.h>

const int MAXN = 100000;

long long val_arr[MAXN],*arr = val_arr + (MAXN>>1);
int beg,end;

signed main(void)
{
    freopen("dance.in","r",stdin);
    freopen("dance.out","w",stdout);
    
    int origNums,totOptn,opt,val,minPos;
    long long s,b;
    
    scanf("%d%d", &origNums,&totOptn);

    if(totOptn <= 8000){
        while(totOptn--){
            scanf("%d", &opt);
            switch(opt){
            case 1:
                scanf("%d", &val);
                --beg;
                break;
            case 2:
                scanf("%d", &val);
                ++end;
                break;
            case 3:
                scanf("%lld%lld", &b,&s);
                for(int i=beg;i<=end;++i)
                    arr[i] += b+s*(i-beg);
                break;
            default: assert(false); break;
            }

            minPos = beg;
            for(int i=beg+1;i<=end;++i)
                if(arr[i] < arr[minPos]) minPos = i;
            printf("%d %lld\n", minPos-beg+1, arr[minPos]);
        }
    } else {
        long long ans = 0;
        while(totOptn--){
            scanf("%d", &opt);
            switch(opt){
            case 1:
                scanf("%d", &val);
                ans = 0;
                break;
            case 3:
                scanf("%lld%lld", &b,&s);
                ans += b;
                break;
            default: assert(false); break;
            }
            printf("%lld\n", ans);
        }
                
    }
    
    return 0;
}
