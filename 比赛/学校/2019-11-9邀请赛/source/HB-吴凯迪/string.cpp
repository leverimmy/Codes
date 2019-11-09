#include<bits/stdc++.h>

int ReadChar(void){
    char in;
    do in = getchar(); while(in!='(' && in!=')');
    return in=='(' ? 1 : -1;
}

const int MAXN = (int)1e6+60;

int totLen;
int val[MAXN];

int Solve(const int& begin){
    int lev=0,len=0;
    for(int i=begin;i<totLen;i++){
        lev += val[i];
        if(lev == 0) len = i-begin+1;
        if(lev < 0) break;
    } return len;
}

signed main(void)
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    
    int len,cnt=0,maxLen=0;

    scanf("%d", &totLen);
    for(int i=0;i<totLen;i++) val[i] = ReadChar();

    for(int i=0;i<totLen;i+=len){
        len = Solve(i);
        if(len > maxLen){ cnt = 1; maxLen = len; }
        else if(len == maxLen) ++cnt;
        if(len <= 0) len = 1;
    }

    printf("%d %d\n", maxLen, cnt);
    
    return 0;
}
