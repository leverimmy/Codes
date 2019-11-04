#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <set>
#include <cmath>
#include <ctime>
#include <iostream>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 500 + 10;
const double k = 0.993;

int n, m, ans, T = 5000;
int a[N], s[N], d[N][N];
int vis[N];

set <int> yes, no;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int random(int l, int r)
{
	return (l == r) ? l : (rand() * rand() % (r - l) + l);
}

int calc()
{
	int res = 0;
	for(rgi i = 1; i <= n; ++i)
	{
		int cur_val1 = oo, cur_val2 = oo;
		if(vis[i])	continue;
		for(rgi j = i - 1; j >= 1; j--)
			if(vis[j])
			{
				cur_val1 = d[i][j];
				break;
			}
		for(rgi j = i + 1; j <= n; ++j)
			if(vis[j])
			{
				cur_val2 = d[i][j];
				break;
			}
		res += min(cur_val1, cur_val2);
	}
	return res;
}

void my_swap(int a, int b)
{
	swap(vis[a], vis[b]);
//	set <int> :: iterator posa = yes.find(a);
//	set <int> :: iterator posb = no.find(b);
	/*for(set <int> :: iterator it = yes.begin(); it != yes.end(); ++it)
		cout << *it << " ";
	cout << endl;
	for(set <int> :: iterator it = no.begin(); it != no.end(); ++it)
		cout << *it << " ";
	cout << endl;*/
	yes.erase(a), no.insert(a);
	no.erase(b), yes.insert(b);
	/*for(set <int> :: iterator it = yes.begin(); it != yes.end(); ++it)
		cout << *it << " ";
	cout << endl;
	for(set <int> :: iterator it = no.begin(); it != no.end(); ++it)
		cout << *it << " ";
	cout << endl;*/
}

void SA()
{
	int cur_ans = ans;
	T = 5000;
	while(T > 1e-14)
	{
		int first = random(1, n);
		while(vis[first] == 0)	first = random(1, n);
		int second = random(1, n);
		while(vis[second] == 1)	second = random(1, n);
		my_swap(first, second);
		int tmp = calc();
		int delta = tmp - cur_ans;
		if(delta < 0)
		{
			cur_ans = tmp;
			if(cur_ans < ans)
				ans = cur_ans;
		}
		else if(exp(-delta / T) * RAND_MAX > rand())
			cur_ans = tmp;
		T *= k;
	}
}

int main()
{
	srand(time(0));
	n = read(), m = read();
	for(rgi i = 2; i <= n; ++i)
	{
		a[i] = read();
		s[i] = s[i - 1] + a[i];
//		t[i] = t[i - 1] + s[i];
	}
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = i + 1; j <= n; ++j)
			d[i][j] = d[j][i] = s[j] - s[i];
	/*for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= n; ++j)
			cout << "i : " << i << "j : " << j << "d[i][j] : " << d[i][j] << endl;
		cout << endl;
	}*/
	for(rgi i = 1; i <= n; ++i)
	{
		if(i <= m)
		{
			vis[i] = 1;
			yes.insert(i);
		}
		else
		{
			vis[i] = 0;
			no.insert(i);
		}
	}
	ans = calc();
//	cout << ans << endl;
	/*for(set <int> :: iterator it = yes.begin(); it != yes.end(); ++it)
		cout << *it << " ";
	cout << endl;
	for(set <int> :: iterator it = no.begin(); it != no.end(); ++it)
		cout << *it << " ";
	cout << endl;*/
	for(rgi i = 1; i <= 100; ++i)
		SA();
	printf("%d", ans);
	return 0;
}

