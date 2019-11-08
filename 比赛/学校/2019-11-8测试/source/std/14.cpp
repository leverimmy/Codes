#include <cstdio>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

const int mo = 10000, w = 4, maxn = 2005;

int t, a[maxn], b[maxn], c[maxn];
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
    for (int i = a[0] - 1; i; i--) printf("%04d", a[i]);
    printf("\n");
}    
    
int main()
{
    freopen("14.in", "r", stdin);
    freopen("14.out", "w", stdout);
    while (cin >> s1 >> s2)
    {
        deal(a, s1); deal(b, s2);
        for (int i = 1; i <= c[0]; ++i) c[i] = 0; c[0] = a[0] + b[0] - 1;
        for (int i = 1; i <= a[0]; ++i)
            for (int j = 1; j <= b[0]; ++j)
            {
                c[i + j - 1] += a[i] * b[j];
                c[i + j] += c[i + j - 1] / mo;
                c[i + j - 1] %= mo;
            }
        if (c[c[0] + 1]) c[0]++;
        while (c[0] && !(c[c[0]])) c[0]--;
        write(c);
    }
    return 0;
}
