#pragma GCC optimize (2)
#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;

int n, m, low, tot, sum;

std::vector <int> vec;
std::vector <int> tmp;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
//	freopen("unhappy.in", "r", stdin);
//	freopen("unhappy.out", "w", stdout);
	n = read(), low = read();
	for(rgi i = 1; i <= n; ++i) {
		string str; int k;
		std::cin >> str >> k;
		if(str == "I") {
			std::vector <int>::iterator it = std::lower_bound(vec.begin(), vec.end(), k);
			vec.insert(it, k); tot++;  
		}
		if(str == "A") {
			for(rgi i = 0; i < vec.size(); ++i)	vec[i] += k;
		}
		if(str == "S") {
			for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
				if(*it - k < low) {
					vec.erase(it);
					it--;
					tot--;sum++;
				}
				else
					*it -= k;
			}
		if(str == "F") {
			if(vec.size() < k)	puts("-1");
			else {
				std::cout << vec[tot - k] << std::endl;
			}
		}
	}
	std::cout << sum << std::endl;
	
	return 0;
}
/*
9 10
I 60
I 70
S 50
F 2
I 30
S 15
A 5
F 1
F 2

*/
