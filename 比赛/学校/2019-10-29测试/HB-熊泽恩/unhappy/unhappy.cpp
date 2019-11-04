#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;

int n, m, low, add, sum, tot;

std::vector <int> vec;
std::vector <int> tmp;

int main() {
//	freopen("unhappy.in", "r", stdin);
//	freopen("unhappy.out", "w", stdout);
	std::cin >> n >> low;
	for(rgi i = 1; i <= n; ++i) {
		string str; int k;
		std::cin >> str >> k;
		if(str == "I") {
			if(k < low)	continue;
			std::vector <int>::iterator it = std::lower_bound(vec.begin(), vec.end(), k - add);
			vec.insert(it, k - add);
		}
		if(str == "A")
			add += k;
		if(str == "S") {
			for(std::vector <int>::iterator it = vec.begin(); it != vec.end(); ++it) {
				if(*it + add - k < low) {
					vec.erase(it);
					it--;
					tot++;
				}
				else
					break;
			}
			add -= k;
//			std::cout << "arr"; for(rgi j = 0; j < vec.size(); ++j)	std::cout << vec[j] << " "; std::cout << std::endl;
//			std::cout << "tot:" << tot << std::endl;
		}
		if(str == "F") {
//			std::cout << "arr"; for(rgi j = 0; j < vec.size(); ++j)	std::cout << vec[j] << " "; std::cout << std::endl;
			if(vec.size() < k)	puts("-1");
			else {
				std::cout << vec[vec.size() - k] + add<< std::endl;
			}
		}
	}
	
	std::cout << tot << std::endl;
	
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
