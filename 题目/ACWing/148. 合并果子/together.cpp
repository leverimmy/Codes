#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue <long long, vector<long long>, greater<long long> > q;

long long n, ans;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        long long cur;
        cin >> cur;
        q.push(cur);
    }
    while(q.size() > 1)
    {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        ans += a + b;
        q.push(a + b);
        // cout << a + b << endl;
    }
    cout << ans;
    return 0;
}
