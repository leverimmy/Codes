#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int main()
{	
	srand(time(NULL));
	freopen("jump1.in","w",stdout);
	cout<<100<<" "<<15<<endl;
	for(int i=1;i<=15;i++)cout<<rand()%100<<" "<<rand()%100<<endl;
	return 0;
}

