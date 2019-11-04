#include <iostream>
#include <queue>

using namespace std;

const int N = 1e6 + 10;

struct node
{
    int id, val;
};

int n, k;
struct node a[N]; deque <struct node> dq1, dq2;
int out1[N], out2[N];

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        struct node tmp;
        cin >> tmp.val;
        tmp.id = i;
        a[i] = tmp;
    }
    for(int i = 1; i <= n; ++i)
    {
        struct node cur = a[i];
        while(!dq1.empty() && cur.val <= dq1.back().val) dq1.pop_back();
        while(!dq2.empty() && cur.val >= dq2.back().val) dq2.pop_back();
        while(!dq1.empty() && cur.id - dq1.front().id + 1 > k)  dq1.pop_front();
        while(!dq2.empty() && cur.id - dq2.front().id + 1 > k)  dq2.pop_front();
        dq1.push_back(cur), dq2.push_back(cur);
        out1[i] = dq1.front().val;
        out2[i] = dq2.front().val;
    }
    for(int i = k; i <= n; ++i)
        cout << out1[i] << " ";
    cout << endl;
    for(int i = k; i <= n; ++i)
        cout << out2[i] << " ";
    return 0;
}
