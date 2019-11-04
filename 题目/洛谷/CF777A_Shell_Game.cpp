#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, x, a[3] = {0, 1, 2};

/*
当n=0时：0,1,2
当n=1时：1,0,2
当n=2时：1,2,0
当n=3时：2,1,0
当n=4时：2,0,1
当n=5时：0,2,1
当n=6时：0,1,2
因此我们可以找到一个循环节为6的循环
*/

int main()
{
	scanf("%d %d", &n, &x);
	n %= 6;
	for(int i = 1; i <= n; i++)
	{
		if(i & 1)
			swap(a[0], a[1]);
		else
			swap(a[1], a[2]);
	}
	printf("%d", a[x]);
	return 0;
}

