#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int year, days, date;
int day_of_Jan, day_of_Feb, day_of_Mar, day_of_Apr, day_of_May;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

int main()
{
	year = read();
	/*if(year % 400 == 0 || (year % 4 == 0 & year % 100 != 0))
		days = 366;
	else
		days = 365;
	day_of_Jan = (year - 1 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + days) % 7;
	day_of_Feb = (day_of_Jan + 3) % 7;
	if(days == 366)
		day_of_Mar = (day_of_Feb + 1) % 7;
	else
		day_of_Mar = day_of_Feb;
	day_of_Apr = (day_of_Mar + 3) % 7;
	day_of_May = (day_of_Apr + 2) % 7;
	int c = year >= 2000 ? 21 : 20;*/
	day_of_May = (1 + 1 + 2 * 5 + 3 * (5 + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
	if(day_of_May == 1)
		puts("14");
	if(day_of_May == 2)
		puts("13");
	if(day_of_May == 3)
		puts("12");
	if(day_of_May == 4)
		puts("11");
	if(day_of_May == 5)
		puts("10");
	if(day_of_May == 6)
		puts("9");
	if(day_of_May == 7)
		puts("8");
	//printf("::%d::", ddd);
	return 0;
}

