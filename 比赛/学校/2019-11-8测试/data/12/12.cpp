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
    for (int i = a[0] - 1; i; i--)
    {
        stringstream R; R << a[i]; s1 = R.str();
        for (int j = 1; j <= w - s1.size(); j++) printf("0");
        cout << s1;
    }
    printf("\n");
}    
    
int main()
{
    freopen("12.in", "r", stdin);
    freopen("12.out", "w", stdout);
    while (cin >> s1 >> s2)
    {
        deal(a, s1); deal(b, s2);
        for (int i = 1; i <= a[0]; ++i)
        {
            a[i] -= b[i]; 
            if (a[i] < 0)
            {
                a[i] += mo; a[i + 1]--;
            }
        }
        while ((a[0] > 1) && (!a[a[0]])) a[0]--;
        write(a); 
    }
    return 0;
}
