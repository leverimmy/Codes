#include <iostream>
#include <vector>
using namespace std;

const int mod = 1000000007;

int main() {
		freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
    int n;
    cin >> n;
    vector<int> help(n + 1);
    help[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        if (i & 1) {
            help[i] = help[i-1];
        }
        else {
            help[i] = (help[i>>1] + help[i-1]) % mod;
        }
    }
    
    cout << help[n] << endl;
    return 0;
}
