#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 100000 + 10;

int n, k, cnt, tot;
int a[N], book[N], kkk[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int random(int l, int r)
{
	if(l == r)
		return l;
	return rand() * rand() % (r - l) + l;
}

int main()
{
	while(1)
	{
		srand(time(0));
		n = random(1, 10), k = random(1, n);
		/*printf("%d %d\n", n, k);*/
		k = n - k;
		for(rgi i = 1; i <= n; ++i)
		{
			a[i] = random(1, 100);
			book[a[i]]++;
		}
		/*for(rgi i = 1; i <= n; ++i)
			cout << a[i] << " ";
		puts("");*/
		for(rgi i = 0; i < N; ++i)
		{
			if(cnt + book[i] < k)
			{
				for(rgi j = 1; j <= book[i]; ++j)
					kkk[++tot] = i;
				cnt += book[i];
			}
			else
			{
				for(rgi j = 1; j <= k - cnt; ++j)
					kkk[++tot] = i;
				break;
			}
		}
		sort(a + 1, a + n + 1);
		for(rgi i = 1; i < k; ++i)
			if(a[i] != kkk[i])
			{
				cout << "fuck!";
				break;
			}
		/*printf("%d %d\n", n, k);
		for(rgi i = 1; i <= n; ++i)
			cout << a[i] << " ";
		puts("");
		for(rgi i = 1; i < k; ++i)
			cout << kkk[i] << " ";*/
		memset(a, 0, sizeof(a));
		memset(book, 0, sizeof(book));
		memset(kkk, 0, sizeof(kkk));
		n = k = cnt = tot = 0;
	}
	return 0;
}

