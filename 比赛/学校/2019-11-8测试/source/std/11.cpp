#include <cstdio>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

const int mo = 100000000, w = 8;

int a[100005], b[100005];
string s1, s2;

void deal(int *a , string st)
{         
    for (int i = 1; i <= a[0]; i++) a[i] = 0; a[0] = 0;
    while (st.size() > w)
    {
        stringstream R(st.substr(st.size() - w, w));
        R >> a[++a[0]];
        st.erase(st.size() - w, w);
    }
    stringstream R(st); R >> a[++a[0]];
}

void write(int *a)
{
    printf("%d", a[a[0]]);
    for (int i = a[0] - 1; i; i--) printf("%08d", a[i]);
    printf("\n");
}       
    
int main()
{
    freopen("11.in", "r", stdin);
    freopen("11.out", "w", stdout);
    while (cin >> s1 >> s2)
    {
        deal(a, s1); deal(b, s2);
        a[0] = max(a[0], b[0]);
        for (int i = 1; i <= a[0]; ++i)
        {
            a[i] += b[i]; 
            a[i + 1] += a[i] / mo;
            a[i] %= mo;
        }
        if (a[a[0] + 1]) a[0]++;
        write(a); 
    }
    return 0;
}
