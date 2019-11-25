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
 
il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x; 
}
 
int main() {
	int a = read(), b = read();
	if(a + 1 == b)
		printf("%d %d", a, b);
	else if(a == 9 && b == 1)
		printf("9 10");
	else if(a == b)
		printf("%d1 %d2", a, b);
	else
		puts("-1");
	return 0;
}
