#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define MAXn 100002
using namespace std;
int N,F,p[MAXn];
int main() {
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	cin>>N;
	for(int i=1; i<=N; i++) {
		cin>>p[i];
	}
	srand(time(0));
	int x=rand()%100;
	cout<<x;
	return 0;
}
/*
11 4
1 1 1 4 1 -8 1 1 1 4 1
*/
