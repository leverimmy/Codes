#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

int n;
std::string str = "";

std::string g(int id) {
	if(id == 1) return "A";
	if(id == 2) return "B";
	if(id == 3) return "C";
	if(id == 4) return "D";
	if(id == 5) return "E";
	if(id == 6) return "F";
	if(id == 7) return "G";
	if(id == 8) return "H";
	if(id == 9) return "I";
	if(id == 10) return "J";
	if(id == 11) return "K";
	if(id == 12) return "L";
	if(id == 13) return "M";
	if(id == 14) return "N";
	if(id == 15) return "O";
	if(id == 16) return "P";
	if(id == 17) return "Q";
	if(id == 18) return "R";
	if(id == 19) return "S";
	if(id == 20) return "T";
	if(id == 21) return "U";
	if(id == 22) return "V";
	if(id == 23) return "W";
	if(id == 24) return "X";
	if(id == 25) return "Y";
	if(id == 26) return "Z";
}

int main() {
	freopen("6.in", "r", stdin);
	freopen("6.out", "w", stdout);
	std::cin >> n;
	for(rgi i = 1; i <= n; ++i)
		str = str + g(i) + str;
	std::cout << str;
	return 0;
}

