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
string a[101];
int t[50];
char ans[10001];
signed main() {
	freopen("2.in", "r", stdin);
	freopen("2.out", "w", stdout);
	int n = read();
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < a[1].length(); i++) {
		memset(t, 0, sizeof(t));
		for(int j = 1; j <= n; j++) {
			if(a[j][i] == 'A') {
				t[1]++;
			}
			if(a[j][i] == 'C') {
				t[2]++;
			}
			if(a[j][i] == 'G') {
				t[3]++;
			}
			if(a[j][i] == 'T') {
				t[4]++;
			}
		}
		int maxx = 0, pp = 0;
		for(int j = 4; j >= 1; j--) {
			if(t[j] >= maxx) {
				pp = j;
				maxx = t[j];
			}
		}
		if(pp == 1) {
			ans[i] = 'A';
		} else if(pp == 2) {
			ans[i] = 'C';
		} else if(pp == 3) {
			ans[i] = 'G';
		} else {
			ans[i] = 'T';
		}
	}
	for(int i = 0; i < a[1].length(); i++) {
		cout << ans[i];
	}
	cout << endl;
	return 0;
} 
