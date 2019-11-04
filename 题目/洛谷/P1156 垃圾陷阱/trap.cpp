#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <map>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int G = 100;

int d, g, flag, ans_no = -oo, ans_yes = oo;
//bool f[G][30 * G + 1][25 * G + 1];

map <int, map<int, map<int, bool> > > f;

struct in
{
	int tim, energy, height;
} R[G];

bool cmp(struct in a, struct in b)
{
	return a.tim < b.tim;
}

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int cur_id, int cur_E, int cur_H)
{
	if(f[cur_id][cur_E][cur_H])
		return;
	f[cur_id][cur_E][cur_H] = 1;
	if(cur_id >= g + 2)
		return;
	if(cur_E >= R[cur_id].tim - R[cur_id - 1].tim)
		cur_E -= R[cur_id].tim - R[cur_id - 1].tim;
	else
	{	
		ans_no = max(ans_no, cur_E + R[cur_id - 1].tim);
		return;
	}
	if(cur_H + R[cur_id].height >= d)
	{
		flag = 1;
		ans_yes = min(ans_yes, R[cur_id].tim);
		return;
	}
	dfs(cur_id + 1, cur_E + R[cur_id].energy, cur_H);
	dfs(cur_id + 1, cur_E, cur_H + R[cur_id].height);
}

int main()
{
	d = read(), g = read();
	for(rgi i = 1; i <= g; ++i)
	{
		R[i].tim = read();
		R[i].energy = read();
		R[i].height = read();
	}
	sort(R + 1, R + g + 1, cmp);
	R[g + 1].tim = oo;
	dfs(1, 10, 0);
	if(flag)
		printf("%d", ans_yes);
	else
		printf("%d", ans_no);
	return 0;
}

