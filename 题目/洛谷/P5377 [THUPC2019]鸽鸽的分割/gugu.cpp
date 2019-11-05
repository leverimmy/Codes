#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

int n; 

int main()
{
    while(std::cin >> n)
        std::cout << (n * n * n * n - 6 * n * n * n + 23 * n * n - 18 * n + 24) / 24 << std::endl;
    return 0;
} 

