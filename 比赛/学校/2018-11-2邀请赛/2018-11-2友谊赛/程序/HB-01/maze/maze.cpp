//
//  main.cpp
//  maze
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
using namespace std;
int n,m,q;
int main() {
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n*m; i++) {
        char ch;
        int num;
        cin>>ch;
        scanf("%d",&num);
        cin>>ch;
        scanf("%d",&num);
    }
    scanf("%d",&q);
    for (int i=1; i<=q; i++) {
        int sx,sy,ex,ey;
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        printf("%d\n",abs(sx-ex)+abs(sy-ey));
    }
    return 0;
}
