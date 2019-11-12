#include<bits/stdc++.h>

const int MAXN = 800000+5;

bool val[MAXN]; long long r[MAXN]; char s[MAXN];
long long Solve(const int& totNums){
    int cnt = 0; r[totNums] = 0;
    for(int i=totNums-1;i>=0;i--){
        r[i] = r[i+1];
        if(val[i]) ++cnt;
        else r[i] += cnt;
    }

    cnt = 0; long long l=0,ans=*r;
    for(int i=0;i<totNums;i++){
        ans = std::min(ans,l+r[i]);
        if(val[i]) ++cnt;
        else l += cnt;
    } return ans;
}

signed main(void)
{
    //freopen("sushi.in","r",stdin);
    //freopen("sushi.out","w",stdout);
    
    int totCases,totNums;

    scanf("%d", &totCases);
    while(totCases--){
        scanf("%s", s); totNums = strlen(s);
        
        for(int i=0;i<totNums;++i) val[i] = s[i]=='B';

        long long ans = Solve(totNums);

        for(int i=0;i<totNums;++i) val[i] = !val[i];

        printf("%lld\n", std::min(ans, Solve(totNums)));
    }
    return 0;
}
