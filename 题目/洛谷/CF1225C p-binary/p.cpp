#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline
 
using namespace std;
 
const int oo = 0x3f3f3f3f;
 
int n, p, flag = 0;
 
il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x; 
}
 
int main() {
	n = read(), p = read();
	
	for(rgi i = 1; i <= 40; ++i) {
		if(n - i * p <= 0)	continue;
		if(__builtin_popcountl(n - i * p) <= i && i <= n - i * p) {
			printf("%d", i);
			flag = 1;
			break;
		}
	}
	if(!flag)
		puts("-1");
		
	
	return 0;
}
