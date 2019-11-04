#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

int lenk, lenc;
std::string k, c;

char solve(char ch1, char ch2) {
	if(ch2 >= 'a') {
		int al1 = ch1 - 'a';
		int al2 = ch2 - 'a';
		return (al2 + 26 - al1) % 26 + 'a';
	}
	else {
		int al1 = ch1 - 'a';
		int al2 = ch2 - 'A';
		return (al2 + 26 - al1) % 26 + 'A';
	}
}

int main() {
	std::cin >> k >> c;
	
	lenk = k.length();
	lenc = c.length();
	
	for(rgi i = 0; i < lenk; ++i)	k[i] = (k[i] < 'a') ? (k[i] - 'A' + 'a') : k[i];
	
	for(rgi i = 0; i < lenc; ++i) {
		
		char cur = k[i % lenk];
		char pro = c[i];
		
		printf("%c", solve(cur, pro));
	}
	
	return 0;
}

