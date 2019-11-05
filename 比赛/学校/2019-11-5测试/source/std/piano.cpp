#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

#define MAXM 305
#define MAXN 30

#define DLEN 4
#define MOD 10000

map <char,int> mp;

int n, m, p;

struct Matrix
{
    int mat[MAXM][MAXM], n;
    Matrix() {}
    Matrix(int _n) { n = _n; for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) mat[i][j] = 0; }
};

struct Trie
{
    int next[MAXM][MAXN], fail[MAXM], tot, root;
    bool end[MAXM];
    
    int newNode() { for (int i = 0; i < MAXN; i++) next[tot][i] = -1; end[tot++] = 0; return tot - 1; }
    
    void init() { tot = 0; root = newNode(); }
    
    void insert(char *ch)
    {
        int len = strlen(ch), o = root;
        for (int i = 0; i < len; i++)
        {
            if (next[o][mp[ch[i]]] == -1) next[o][mp[ch[i]]] = newNode();
            o = next[o][mp[ch[i]]];
        }
        end[o] = 1;
    }
    
    void build()
    {
        queue <int> Q;
        fail[root] = root;
        for (int i = 0; i < MAXN; i++)
            if (next[root][i] == -1) next[root][i] = root;
            else fail[next[root][i]] = root, Q.push(next[root][i]);
        while (!Q.empty())
        {
            int o = Q.front(); Q.pop();
            if (end[fail[o]]) end[o] = 1;
            for (int i = 0; i < MAXN; i++)
                if (next[o][i] == -1) next[o][i] = next[fail[o]][i];
                else fail[next[o][i]] = next[fail[o]][i], Q.push(next[o][i]);
        }
    }
    
    Matrix getMatrix()
    {
        Matrix res = Matrix(tot);
        for (int i = 0; i < tot; i++)
            for (int j = 0; j <= n - 1; j++)
                if (!end[next[i][j]]) res.mat[i][next[i][j]]++;
        return res;
    }
};

struct ubInt
{
    int a[600], len;
    ubInt() { memset(a, 0, sizeof(a)), len = 1; }
    ubInt(int o)
    {
        memset(a, 0, sizeof(a)), len = 0;
        do { a[len++] = o % MOD, o /= MOD; } while (o);
    }
    
	ubInt(const char s[])
    {
        memset(a, 0, sizeof(a));
        int nl = strlen(s), ind = 0; len = nl / DLEN;
        if (nl % DLEN) len++;
        for (int i = nl - 1; i >= 0; i -= DLEN)
        {
            int t = 0, k = i - DLEN + 1;
            if (!k) k = 0;
            for (int j = k; j <= i; j++) t = t * 10 + s[j] - '0';
            a[ind++] = t;
        }
    }
    
    ubInt operator + (const ubInt &b) const
    {
        ubInt res;
        res.len = max(len, b.len);
        for (int i = 0; i <= res.len; i++) res.a[i] = 0;
        for (int i = 0; i < res.len; i++)
        {
            res.a[i] += (i < len ? a[i] : 0) + (i < b.len ? b.a[i] : 0);
            res.a[i+1] += res.a[i] / MOD;
            res.a[i] %= MOD;
        }
        if (res.a[res.len] > 0) res.len++;
        return res;
    }
    
    ubInt operator * (const ubInt &b) const
    {
        ubInt res;
        for (int i = 0; i < len; i++)
        {
            int up = 0;
            for (int j = 0; j < b.len; j++)
            {
                int temp = a[i] * b.a[j] + res.a[i + j] + up;
                res.a[i + j] = temp % MOD;
                up = temp / MOD;
            }
            if (up != 0) res.a[i + b.len] = up;
        }
        res.len = len + b.len;
        while (res.a[res.len - 1] == 0 && res.len > 1) res.len--;
        return res;
    }
    
    bool noAns() { for (int i = 0; i <= len - 1; i++) if (a[i] != 0) return 0; return 1; }
	
    void print()
    {
    	if (noAns()) printf("-1");
    	else
    	{
        	printf("%d", a[len - 1]);
        	for (int i = len - 2; i >= 0; i--) printf("%04d", a[i]);
        	printf("\n");
        }
    }
};

char ch[MAXM], dict[MAXM];
ubInt dp[2][MAXM];
Trie AC;
Matrix a;

void DP()
{
    int o = 0;
    dp[o][0] = 1;
    for (int i = 0; i <= m - 1; i++)
    {
        o ^= 1;
    	for (int j = 0; j < a.n; j++) dp[o][j] = 0;
        for (int j = 0; j < a.n; j++)
            for (int k = 0; k < a.n; k++)
                if (a.mat[j][k] > 0) dp[o][k] = dp[o][k] + dp[o ^ 1][j] * a.mat[j][k];
    }
    ubInt ans = 0;
    for (int i = 0; i < a.n; i++) ans = ans + dp[o][i]; ans.print();
}

int main()
{
    freopen("piano.in", "r", stdin);
    freopen("piano.out", "w", stdout);
    scanf("%d %d %d %s", &n, &m, &p, dict);
    mp.clear(); for (int i = 0; i <= n - 1; i++) mp[dict[i]] = i;
    AC.init();
    for (int i = 0; i <= p - 1; i++) scanf("%s", ch), AC.insert(ch);
    AC.build(), a = AC.getMatrix();
    DP();
    return 0;
}
