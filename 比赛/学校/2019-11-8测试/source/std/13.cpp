#include <cstdio>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

const int mo = 10000, w = 4;

int t, a[100005];
string s1;

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
    freopen("13.in", "r", stdin);
    freopen("13.out", "w", stdout);
    while (cin >> s1)
    {
        deal(a, s1); scanf("%d", &t);
        for (int i = 1; i <= a[0]; ++i) a[i] *= t;
        for (int i = 1; i <= a[0]; ++i)
        {
            a[i + 1] += a[i] /mo; a[i] %= mo;
        }
        if (a[a[0] + 1]) a[0]++;
        while ((a[0] > 1) && !a[a[0]]) a[0]--;
        write(a); 
    }
    return 0;
}
