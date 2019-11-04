#include<bits/stdc++.h>

using namespace std;

char getch(){
    static char buf[100000],*s,*t;
    return (s == t) && (t = (s = buf) + fread(buf,1,100000,stdin)),s == t ? EOF : *s++;
}

typedef long long int_t;

int_t read(){
    int_t x = 0,w = 1;char ch = 0;
    while(ch < '0' || ch > '9') {ch = getch();if(ch == '-') w = -1;}
    while(ch >='0' && ch <='9') x = x * 10 + ch - '0', ch = getch();
    return x * w;
}

const int_t p1 = 998244353,p2 = 1000000007;

int_t powedp1[100010],powedp2[100010];
int_t Power[100010];
int_t hash1[100010],hash2[100010];

int main(){
    freopen("weapon.in","r",stdin);
    freopen("weapon.out","w",stdout);
    int_t n = read(),F = read();
    powedp1[0] = powedp2[0] = 1;
    for(int_t i=1;i<=n;i++) 
        Power[i] = read(),
        powedp1[i] = powedp1[i-1] * 7 % p1,
        powedp2[i] = powedp2[i-1] * 7 % p2;
    for(int_t i=1;i<=n;i++) 
        hash1[i] = (hash1[i-1] + Power[i] * powedp1[i] % p1) % p1,
        hash2[i] = (hash2[i-1] + Power[i] * powedp2[i] % p2) % p2;
    int_t ans = 0;
    for(int_t a=1;a<=n;a++)
        for(int_t len=1;a + len * 2 + F - 1 <= n;len++)
            //[a,a+len-1], [a+len+F,a+len*2+F-1]
            if(((hash1[a+len-1] - hash1[a-1]) * powedp1[len + F] % p1 - (hash1[a+len*2+F-1] - hash1[a+len+F-1])) % p1 == 0 && 
               ((hash2[a+len-1] - hash2[a-1]) * powedp2[len + F] % p2 - (hash2[a+len*2+F-1] - hash2[a+len+F-1])) % p2 == 0) ++ans;
    cout<<ans;
}