#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e5 + 10;

int n, cnt, nxt[N], vis[N];
int a[N], sortA[N];
int b[N], sortB[N];

std::map <int, int> rankA, rankB;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read();
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	for(rgi i = 1; i <= n; ++i)	b[i] = read();
	//Input
	
	for(rgi i = 1; i <= n; ++i)	sortA[i] = a[i];
	for(rgi i = 1; i <= n; ++i)	sortB[i] = b[i];
	std::sort(sortA + 1, sortA + n + 1);
	std::sort(sortB + 1, sortB + n + 1);
	//Smallest Permutation
	
	for(rgi i = 1; i <= n; ++i) rankA[sortA[i]] = i;
	for(rgi i = 1; i <= n; ++i)	rankB[sortB[i]] = i;
	//Discrete 
	
	for(rgi i = 1; i <= n; ++i)	if(sortA[i] > sortB[i]) {
		puts("No");
		return 0;
	}
	
	for(rgi i = 1; i <= n - 1; ++i)	if(sortA[i + 1] <= sortB[i]) {
		puts("Yes");
		return 0;
	}
	//Exclusion
	
	for(rgi i = 1; i <= n; ++i) nxt[rankB[b[i]]] = rankA[a[i]];
	//Add edges
	
	for(rgi i = 1; i <= n; ++i) {
		if(!vis[i]) {
			int cur = i;
			do {
				vis[cur] = 1;
				cur = nxt[cur];
			} while(!vis[cur]); 
			cnt++;
		}
	}
	
	puts(cnt == 1 ? "No" : "Yes");
	
	return 0;
}

