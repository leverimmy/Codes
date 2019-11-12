#include<bits/stdc++.h>

bool ReadChar(void){
    char in;
    do in = getchar(); while(in!='0' && in!='1');
    return in=='1';
}

const int MAXN = 5050;

bool s[MAXN][MAXN];
int suf[MAXN][MAXN];

int cnt[MAXN];

signed main(void)
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    
    int totLine,totList;

    scanf("%d%d", &totLine,&totList);
    for(int i=0;i<totLine;i++)
        for(int j=0;j<totList;j++)
            s[i][j] = ReadChar();

    for(int i=0;i<totLine;i++)
        for(int j=totList-1;j>=0;j--)
            if(s[i][j]) suf[i][j] = 1 + suf[i][j+1];
            else suf[i][j] = 0;
    
    int max = 0, now;
    for(int begin=0;begin<totList;begin++){
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<totLine;i++) cnt[suf[i][begin]]++;
        now = totLine;
        for(int i=0;i<=totList;i++){
            max = std::max(max, now*i); now -= cnt[i];
        }
    }

    printf("%d\n", max);
    
    return 0;
}
