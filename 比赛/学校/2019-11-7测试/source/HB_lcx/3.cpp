#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {
		if(c == '-') {
			f = -1;
		}
		c = getchar();
	} 
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
string num;
string ans[10001];
int cnt;
string a[11] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string wss[3] = {"", "wan", "yi"};
signed main() {
//	freopen("3.in", "r", stdin);
//	freopen("3.out", "w", stdout);
	cin >> num;
	int lenn = num.length();
	for(int i = 0; i < lenn; i++) {
		if((lenn - i) % 4 == 1) {
			if(num[i] != '0') {
				cout << a[num[i] - '0'] << ' ' << wss[((lenn - i) / 4)] << ' ';
			} else {
				bool flag = true;
				for(int j = i; j >= max(i - 3, 0ll); j--) {
					if(num[j] != '0') {
						break;
					}
					if(j == max(i - 3, 0ll) && num[j] == '0') {
						flag = false;
					}
				}
				if(flag) {
					cout << wss[(lenn - i) / 4] << ' ';
				} 
			}
		}
		if((lenn - i) % 4 == 2) {
			if(num[i] == '1' && num[i + 1] != '0' && num[i - 1] == '0') {
				cout << "shi" << ' ';
			} else if(num[i] != '0') {
				cout << a[num[i] - '0'] << ' ' << "shi" << ' ';
			} else if(num[i + 1] != '0' && num[i - 1] != '0') {
				cout << "ling" << ' ';
			}
		} 
		if((lenn - i) % 4 == 3) {
			if(num[i] != '0') {
				cout << a[num[i] - '0'] << ' ' << "bai" << ' ';
			} else if(num[i - 1] != '0' && num[i + 1] != '0') {
				cout << "ling" << ' ';
			}
		}
		if((lenn - i) % 4 == 0) {
			if(num[i] != '0') {
				cout << a[num[i] - '0'] << ' ' << "qian" << ' ';
			} else if(num[i + 3] != '0' && num[i + 1] != '0' && num[i + 2] != '0' ) {
				cout << "ling" << ' ';
			}
		}
		for(int j = i + 1; j <= lenn - 1; j++) {
			if(num[j] != '0') {
				break;
			}
			if(j == i - 1) {
				cout << wss[(lenn - i) / 4] << ' ';
				return 0;
			} 
		}
	}
	return 0;
} 
