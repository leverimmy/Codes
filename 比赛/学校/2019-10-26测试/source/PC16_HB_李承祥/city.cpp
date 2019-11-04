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
	return x * f;//mythware_super_password
}					
int a[50001];		
signed main() {		
	freopen("city.in", "r", stdin);
	freopen("city.out", "w", stdout);
	int n = read();	
	for(int i = 1; i <= n * (n - 1) / 2; i++) {
		a[i] = read();
	}				
	sort(a + 1, a + 1 + n * (n - 1) / 2);
					
	return 0;		
}					
