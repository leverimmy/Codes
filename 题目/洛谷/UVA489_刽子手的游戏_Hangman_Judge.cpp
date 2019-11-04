#include <cstdio>
#include <cstring>

using namespace std;

int id, left, chance, win, lose, len1, len2;
char _target[10010];
char _guess[10010];

void print_win()
{
	printf("You win.\n");
}

void print_lose()
{
	printf("You lose.\n");
}

void print_chi()
{
	printf("You chickened out.\n");
}

void guess(char ch)
{
	int is_wrong = 1;
	for(int i = 0; i <= len1; i++)
	{
		if(_target[i] == ch)
		{
			left--;
			_target[i] = ' ';
			is_wrong = 0;
		}
	}
	if(is_wrong)
		chance--;
	if(!chance)
		lose = 1;
	if(!left)
		win = 1;
}

int main()
{
	while(scanf("%d%s%s", &id, _target, &_guess) && (id != -1))
	{
		left = strlen(_target);
		chance = 7;
		win = 0;
		lose = 0;
		len1 = strlen(_target);
		len2 = strlen(_guess);
		printf("Round %d\n", id);
		for(int i = 0; i < len2; i++)
		{
			guess(_guess[i]);
			if(win || lose)
				break;
		}
		if(win)
			print_win();
		else if(lose)
			print_lose();
		else
			print_chi();
	}
	return 0;
}
