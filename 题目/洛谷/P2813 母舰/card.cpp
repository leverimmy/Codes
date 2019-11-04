#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline
#define iter set <int> :: iterator 


using namespace std;

const int oo = 0x3f3f3f3f;

int n, m, sum;

multiset <int> def, atk;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	m = read(), n = read();
	for(rgi i = 1; i <= m; ++i) def.insert(-read());
	for(rgi i = 1; i <= n; ++i) atk.insert(-read());
	for(multiset <int> :: iterator it = atk.begin(); it != atk.end(); ++it) {
		iter pos = upper_bound(def.begin(), def.end(), *it);
		if(pos == def.end()) break;
		/*printf("%d %d\n", *pos, *it);*/
		def.erase(*pos); atk.erase(*it);
		/*printf("ATK"); for(multiset <int> :: iterator it2 = atk.begin(); it2 != atk.end(); ++it2)
			printf("%d ", *it2);
		puts("");
		printf("DEF"); for(multiset <int> :: iterator it3 = def.begin(); it3 != def.end(); ++it3)
			printf("%d ", *it3);
		puts("");*/
	}
	if(!def.size()) {
		for(multiset <int> :: iterator it = atk.begin(); it != atk.end(); ++it) sum += *it;
		printf("%d", -sum);
	}
	else	puts("0");
	return 0;
}
/*
3 5 
1000 2000 1200 
2100 2000 1200 1000 1000

*/
