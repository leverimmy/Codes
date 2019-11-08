#include <cstdio>
#include <cstring>
using namespace std;
int n, m, next[100010];
char s[100010], t[100010];
bool ok;

int main()
{
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);
    while (scanf("%s%s", s, t) != EOF)
    {
        n = strlen(s); m = strlen(t); ok = false;
        int j = -1; next[0] = -1;
        for (int i = 1; i < m; ++i)
        {
            while ((j >= 0) && (t[j + 1] != t[i])) j = next[j];
            if (t[j + 1] == t[i]) j++;
            next[i] = j;
        }
        j = -1;
        for (int i = 0; i < n; ++i)
        {
            while ((j >= 0) && (t[j + 1] != s[i])) j = next[j];
            if (t[j + 1] == s[i]) j++;
            if (j == m - 1)
            {
                ok = true; break;
            }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }   
    return 0;   
}
