#include <cstdio>
#include <cstring>

using namespace std;

int t, s, x, delta;

int main()
{
	scanf("%d %d %d", &t, &s, &x);
	delta = x - t;//delta是中间间隔的时间 
	if(delta >= 0 && delta != 1 && (delta % s == 1 || delta % s == 0))
		printf("YES");//如果delta是正的，题目说了不会在t+1的时候叫
					  //如果delta%s的值是1或者是0，就会叫 
	else
		printf("NO");
	return 0;
}

