#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int siz, len;
string s, s1, s2, s3, s4, s5;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	siz = read();
	cin >> s;
	s = " " + s;
	len = s.length();
	for(rgi i = 1; i < len; i++)
	{
		switch(s[i])
		{
			case '1':
			{
				for(rgi j = 1; j <= 3 + siz; j++)
					s1 = s1 + " ";
				for(rgi j = 1; j <= 1 + siz; j++)
					s2 = s2 + " ";
				s2 = s2 + "|" + " ";
				for(rgi j = 1; j <= 3 + siz; j++)
					s3 = s3 + " ";
				for(rgi j = 1; j <= 1 + siz; j++)
					s4 = s4 + " ";
				s4 = s4 + "|" + " ";
				for(rgi j = 1; j <= 3 + siz; j++)
					s5 = s5 + " ";
				break;
			}
			case '2':
			{
				s1 = s1 + " ";
				for(rgi j = 1; j <= siz; j++)
					s1 = s1 + "-";
				s1 = s1 + "  ";
				for(rgi j = 1; j <= 1 + siz; j++)
					s2 = s2 + " ";
				s2 = s2 + "|" + " ";
				s3 = s3 + " ";
				for(rgi j = 1; j <= siz; j++)
					s3 = s3 + "-";
				s3 = s3 + "  ";
				s4 = s4 + "|";
				for(rgi j = 1; j <= 2 + siz; j++)
					s4 = s4 + " ";
				s5 = s5 + " ";
				for(rgi j = 1; j <= siz; j++)
					s5 = s5 + "-";
				s5 = s5 + "  ";
				break;
			}
			case '3':
			{
				s1 = s1 + " ";
				for(rgi j = 1; j <= siz; j++)
					s1 = s1 + "-";
				s1 = s1 + "  ";
				for(rgi j = 1; j <= siz + 1; j++)
					s2 = s2 + " ";
				s2 = s2 + "|" + " ";
				s3 = s3 + " ";
				for(rgi j = 1; j <= siz; j++)
					s3 = s3 + "-";
				s3 = s3 + "  ";
				for(rgi j = 1; j <= siz + 1; j++)
					s4 = s4 + " ";
				s4 = s4 + "|" + " ";
				s5 = s5 + " ";
				for(rgi j = 1; j <= siz; j++)
					s5 = s5 + "-";
				s5 = s5 + "  ";
				break;
			}
			case '4':
			{
				for(rgi j = 1; j <= 3 + siz; j++)
					s1 = s1 + " ";
				s2 = s2 + "|";
				for(rgi j = 1; j <= siz; j++)
					s2 = s2 + " ";
				s2 = s2 + "|" + " ";
				s3 = s3 + " ";
				for(rgi j = 1; j <= siz; j++)
					s3 = s3 + "-";
				s3 = s3 + "  ";
				for(rgi j = 1; j <= siz + 1; j++)
					s4 = s4 + " ";
				s4 = s4 + "|" + " ";
				for(rgi j = 1; j <= 3 + siz; j++)
					s5 = s5 + " ";
				break;
			}
			case '5':
			{
				s1 = s1 + " ";
				for(rgi j = 1; j <= siz; j++)
					s1 = s1 + "-";
				s1 = s1 + "  ";
				s2 = s2 + "|";
				for(rgi j = 1; j <= 2 + siz; j++)
					s2 = s2 + " ";
				s3 = s3 + " ";
				for(rgi j = 1; j <= siz; j++)
					s3 = s3 + "-";
				s3 = s3 + "  ";
				for(rgi j = 1; j <= siz + 1; j++)
					s4 = s4 + " ";
				s4 = s4 + "|" + " ";
				s5 = s5 + " ";
				for(rgi j = 1; j <= siz; j++)
					s5 = s5 + "-";
				s5 = s5 + "  ";
				break;
			}
			case '6':
			{
				s1 = s1 + " ";
				for(rgi j = 1; j <= siz; j++)
					s1 = s1 + "-";
				s1 = s1 + "  ";
				s2 = s2 + "|";
				for(rgi j = 1; j <= 2 + siz; j++)
					s2 = s2 + " ";
				s3 = s3 + " ";
				for(rgi j = 1; j <= siz; j++)
					s3 = s3 + "-";
				s3 = s3 + "  ";
				s4 = s4 + "|";
				for(rgi j = 1; j <= siz; j++)
					s4 = s4 + " ";
				s4 = s4 + "|" + " ";
				s5 = s5 + " ";
				for(rgi j = 1; j <= siz; j++)
					s5 = s5 + "-";
				s5 = s5 + "  ";
				break;
			}
			case '7':
			{
				s1 = s1 + " ";
				for(rgi j = 1; j <= siz; j++)
					s1 = s1 + "-";
				s1 = s1 + "  ";
				for(rgi j = 1; j <= 1 + siz; j++)
					s2 = s2 + " ";
				s2 = s2 + "|" + " ";
				for(rgi j = 1; j <= 3 + siz; j++)
					s3 = s3 + " ";
				for(rgi j = 1; j <= 1 + siz; j++)
					s4 = s4 + " ";
				s4 = s4 + "|" + " ";
				for(rgi j = 1; j <= 3 + siz; j++)
					s5 = s5 + " ";
				break;
			}
			case '8':
			{
				s1 = s1 + " ";
				for(rgi j = 1; j <= siz; j++)
					s1 = s1 + "-";
				s1 = s1 + "  ";
				s2 = s2 + "|";
				for(rgi j = 1; j <= siz; j++)
					s2 = s2 + " ";
				s2 = s2 + "|" + " ";
				s3 = s3 + " ";
				for(rgi j = 1; j <= siz; j++)
					s3 = s3 + "-";
				s3 = s3 + "  ";
				s4 = s4 + "|";
				for(rgi j = 1; j <= siz; j++)
					s4 = s4 + " ";
				s4 = s4 + "|" + " ";
				s5 = s5 + " ";
				for(rgi j = 1; j <= siz; j++)
					s5 = s5 + "-";
				s5 = s5 + "  ";
				break;
			}
			case '9':
			{
				s1 = s1 + " ";
				for(rgi j = 1; j <= siz; j++)
					s1 = s1 + "-";
				s1 = s1 + "  ";
				s2 = s2 + "|";
				for(rgi j = 1; j <= siz; j++)
					s2 = s2 + " ";
				s2 = s2 + "|" + " ";
				s3 = s3 + " ";
				for(rgi j = 1; j <= siz; j++)
					s3 = s3 + "-";
				s3 = s3 + "  ";
				for(rgi j = 1; j <= 1 + siz; j++)
					s4 = s4 + " ";
				s4 = s4 + "|" + " ";
				s5 = s5 + " ";
				for(rgi j = 1; j <= siz; j++)
					s5 = s5 + "-";
				s5 = s5 + "  ";
				break;
			}
			case '0':
			{
				s1 = s1 + " ";
				for(rgi j = 1; j <= siz; j++)
					s1 = s1 + "-";
				s1 = s1 + "  ";
				s2 = s2 + "|";
				for(rgi j = 1; j <= siz; j++)
					s2 = s2 + " ";
				s2 = s2 + "|" + " ";
				for(rgi j = 1; j <= siz + 3; j++)
					s3 = s3 + " ";
				s4 = s4 + "|";
				for(rgi j = 1; j <= siz; j++)
					s4 = s4 + " ";
				s4 = s4 + "|" + " ";
				s5 = s5 + " ";
				for(rgi j = 1; j <= siz; j++)
					s5 = s5 + "-";
				s5 = s5 + "  ";
				break;
			}
		}
	}
	cout << s1 << endl;
	for(rgi i = 1; i <= siz; i++)
		cout << s2 << endl;
	cout << s3 << endl;
	for(rgi i = 1; i <= siz; i++)
		cout << s4 << endl;
	cout << s5;
}

