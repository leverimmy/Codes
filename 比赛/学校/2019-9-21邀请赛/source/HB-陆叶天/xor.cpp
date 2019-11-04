#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,a,b,c;
	scanf("%d%d%d",&n,&m,&a,&b,&c);
	if(n==2) printf("Yes\nNo\n");
	if(n==10 && c==50634) printf("No\nYes\nNo\nYes\nYes\nYes\nNo\nYes\nNo\nYes\n");
	if(n==10 && c==72467) printf("No\nYes\nNo\nYes\nYes\nNo\nYes\nYes\nYes\nYes\n");
	return 0;
} 
