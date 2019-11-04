#include <iostream>
using namespace std;
int n, tmp, ans;
int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> tmp;
        ans ^= tmp;
    }
    cout << (ans ? "Yes" : "No");
    return 0;
}
