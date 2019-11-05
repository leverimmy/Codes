#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

#define MSET std::multiset <int>::iterator

const int oo = 0x3f3f3f3f;
const int N = 5e5 + 10;

int n, m, MIN_SORT_GAP = oo;

std::string str;
std::vector <int> vec[N];
std::multiset <int> num, gap;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i) {
		
		int w = read();
		
		vec[i].push_back(w);
		if(i != 1)	gap.insert(abs(vec[i - 1][0] - w));
		/*updating MIN_GAP*/
		
		num.insert(w);
		MSET it = num.find(w);
		if(it != num.begin()) {
			MIN_SORT_GAP = std::min(MIN_SORT_GAP, abs(*(--it) - w));
			it++;
		}
		it++;
		if(it != num.end())
			MIN_SORT_GAP = std::min(MIN_SORT_GAP, abs(*it - w));
		/*updating MIN_SORT_GAP*/
	}
	
	for(rgi i = 1; i <= m; ++i) {
		char str[20];	scanf("%s", str);
		if(str[0] == 'I') {
			
			int pos = read(), w = read();
			
			vec[pos].push_back(w);
			if(pos != n) {
				gap.erase(gap.find(abs(vec[pos + 1][0] - vec[pos][vec[pos].size() - 2])));
				gap.insert(abs(vec[pos + 1][0] - w));
			}
			gap.insert(abs(vec[pos][vec[pos].size() - 2] - w));
			/*updating MIN_GAP*/
			
			num.insert(w);
			MSET it = num.find(w);
			if(it != num.begin()) {
				MIN_SORT_GAP = std::min(MIN_SORT_GAP, abs(*(--it) - w));
				it++;
			}
			it++;
			if(it != num.end())
				MIN_SORT_GAP = std::min(MIN_SORT_GAP, abs(*it - w));
			/*updating MIN_SORT_GAP*/
		}
		if(str[4] == 'G')
			printf("%d\n", *gap.begin());
		if(str[4] == 'S')
			printf("%d\n", MIN_SORT_GAP);
	}
	return 0;
}

