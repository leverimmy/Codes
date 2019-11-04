#include <cstdio>

using namespace std;

int money;

int main()
{
	scanf("%d",&money);
	money-=5000;
	if(0<money && money<=3000)
	{
		money=money*97/100;
	}
	else if(3000<money && money<=12000)
	{
		money=(money-3000)*90/100+3000*0.97;
	}
	else if(12000<money && money<=25000)
	{
		money=(money-12000)*80/100+3000*0.97+9000*0.9;
	}
	else if(25000<money && money<=35000)
	{
		money=(money-25000)*75/100+3000*0.97+9000*0.9+13000*0.8;
	}
	else if(35000<money && money<=55000)
	{
		money=(money-35000)*70/100+3000*0.97+9000*0.9+13000*0.8+10000*0.75;
	}
	else if(55000<money && money<=80000)
	{
		money=(money-55000)*65/100+3000*0.97+9000*0.9+13000*0.8+10000*0.75+20000*0.7;
	}
	else if(80000<money)
	{
		money=(money-80000)*55/100+3000*0.97+9000*0.9+13000*0.8+10000*0.75+20000*0.7+25000*0.65;
	}
	money+=5000;
	printf("%d",money);
	return 0;
}