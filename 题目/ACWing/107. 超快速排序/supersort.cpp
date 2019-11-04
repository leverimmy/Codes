#include <iostream>
#include <cstring>
#define ll long long

using namespace std;
const int N = 5e5 + 10;

int n;
ll ans;
int a[N], tmp[N];

void Merge_Sort(int l, int r, int q[])
{
    if(l >= r)
        return;
    int mid = l + r >> 1;
    Merge_Sort(l, mid, q);
    Merge_Sort(mid + 1, r, q);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r)
        if(q[i] < q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++], ans += mid - i + 1;
    while(i <= mid)
        tmp[k++] = q[i++];
    while(j <= r)
        tmp[k++] = q[j++];
    for(int i = l, j = 0; i <= r; ++i, ++j)
        q[i] = tmp[j];
}

int main()
{
    while(cin >> n)
    {
        if(!n)
            break;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        Merge_Sort(1, n, a);
        cout << ans << endl;
        ans = n = 0;
        memset(a, 0, sizeof(a));
    }
    return 0;
}
