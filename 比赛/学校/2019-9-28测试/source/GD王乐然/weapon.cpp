// Leran Wang, 2019/09/27, prepared for scoring 0
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <cstdio>
using namespace std;

#define MAXN 100050
typedef pair<int, int> Parameter;
typedef pair<int, int> Range;
int n, f, p[MAXN];
map<int, vector<int> > rle;
map<int, vector<Range> > rs;
set<Parameter> methods;

Range intersection(Range ra, Range rb) {
	if (ra.second < rb.first || rb.second < ra.first)
		return Range(-1, -2);
	return Range(max(ra.first, rb.first), min(ra.second, rb.second));
}

int main() {
	freopen("weapon.in", "r", stdin);
	freopen("weapon.out", "w", stdout);
	cin >> n >> f;
	for (int i = 0; i < n; i++)
		cin >> p[i];
		
	for (int i = 0; i < n; i++) {
		if (!rle.count(p[i])) {
			rle[p[i]] = vector<int> ();
		}
		rle[p[i]].push_back(i);
	}
	
//	for (map<int, vector<int> >::iterator it = rle.begin();\
//	  it != rle.end(); it++) {
//		// v = it->first
//		cout << it->first << ": " << endl;
//		for (const int& r : it->second) {
//			cout << r << " ";
//		}
//		cout << endl << endl;
//	}
		
	for (map<int, vector<int> >::iterator it = rle.begin();\
	  it != rle.end(); it++) {
		int v = it->first;
		Range r = make_pair(it->second[0], it->second[0]);
		for (int i = 1; i < it->second.size(); i++) {
			if (it->second[i] == r.second + 1) {
//				cout << "(" << r.first << ", " << r.second << ") " << v << ", " << it->second[i] << endl;
				r.second = it->second[i];
			} else {
				if (!rs.count(v))
					rs[v] = vector<Range>();
				rs[v].push_back(r);
				r = make_pair(it->second[i], it->second[i]);
			}
		}
		rs[it->first].push_back(r);
	}
	
	int ans = 0;
	
//	for (map<int, vector<Range> >::iterator it = rs.begin();\
//	  it != rs.end(); it++) {
//		// v = it->first
//		cout << it->first << ": " << endl;
//		for (const Range& r : it->second) {
//			cout << "(" << r.first << ", " << r.second << ") ";
//		}
//		cout << endl << endl;
//	}

	for (map<int, vector<Range> >::iterator it = rs.begin();\
	  it != rs.end(); it++) {
		// v = it->first
		int v = it->first;
		vector<Range>& rv = it->second;
		for (int i = 0; i < rv.size() - 1; i++)
			for (int j = i + 1; j < rv.size(); j++) {
				int maxl = min(rv[i].second - rv[i].first, rv[j].second - rv[j].first) + 1;
				for (int l = 1; l <= maxl; l++) {
					Range c1 = make_pair(rv[i].first, rv[i].second - l + 1),\
					  c2 = make_pair(rv[j].first - l - f, rv[j].second - 2 * l - f + 1),\
					  c3 = make_pair(2 - f - 2 * l, n + 1 - f - 2 * l);
					Range res = make_pair(1, n);
					res = intersection(res, c1);
					res = intersection(res, c2);
					res = intersection(res, c3);
					
					if (res.second >= res.first) {
						ans += res.second - res.first + 1;
//						cout << "[" << rv[i].first << ", " << rv[i].second << "] & [" << rv[j].first << ", " << rv[j].second << "]" << endl;
//						cout << "maxl = " << maxl << ", l = " << l << endl;
//						cout << "a \\in [" << res.first << ", " << res.second << "]" << endl;
					}
				}
			}
	}
	
	cout << ans << endl;
	return 0;
}

