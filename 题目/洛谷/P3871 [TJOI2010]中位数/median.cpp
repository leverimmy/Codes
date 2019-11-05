#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

int n, m, val;

std::vector <int> vec;
std::string str;

int main() {
	
	std:: cin >> n;
	
	for(rgi i = 1; i <= n; ++i) {
		int val;	std::cin >> val;
		vec.push_back(val);
	}
	
	std::sort(vec.begin(), vec.end());
	
	std::cin >> m;
	
	for(rgi i = 1; i <= m; ++i) {
		std::cin >> str ;
		if(str == "add") {
			std:: cin >> val;
			std::vector <int>::iterator pos = std::lower_bound(vec.begin(), vec.end(), val);
			vec.insert(pos, val);
		}
		if(str == "mid") {
			if(vec.size() & 1)
				std::cout << vec[vec.size() - 1 >> 1] << std::endl;
			else
				std::cout << std::min(vec[(vec.size() >> 1) - 1], vec[vec.size() >> 1]) << std::endl;
		}
	}
	
	return 0;
}

