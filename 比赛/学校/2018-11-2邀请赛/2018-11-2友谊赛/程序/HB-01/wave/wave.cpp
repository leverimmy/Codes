//
//  main.cpp
//  wave
//
//  Created by 童维希 on 2018/11/2.
//  Copyright © 2018 童维希. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <string>
#define maxn 100001
#define ll long long
using namespace std;
int n;
long long ans;
long long inx[maxn],iny[maxn],maxheng[maxn],maxshu[maxn],tmpx[maxn],tmpy[maxn];

int main() {
    freopen("wave.in", "r", stdin);
    freopen("wave.out", "w", stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%lld%lld",&inx[i],&iny[i]);
        tmpx[i]=inx[i];
        tmpy[i]=iny[i];
    }
    sort(tmpx+1,tmpx+1+n);
    sort(tmpy+1,tmpy+1+n);
    long sizex=unique(tmpx+1, tmpx+1+n)-tmpx;
    long sizey=unique(tmpy+1, tmpy+1+n)-tmpy;
    for (int i=n; i>=1; i--) {
        for (int j=1; j<=inx[i]; j++) {
            long y=lower_bound(tmpy+1, tmpy+1+sizey, iny[i])-tmpy+1;
            if (maxshu[j]<y){
                maxshu[j]=y;
                ans++;
            }
        }
        for (int j=1; j<=iny[i]; j++) {
            long x=lower_bound(tmpx+1, tmpx+1+sizex, inx[i])-tmpx+1;
            if (maxheng[j]<x) {
                maxheng[j]=x;
                ans++;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
