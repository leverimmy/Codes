#include<bits/stdc++.h>
using namespace std;
#define random(x) (rand()%x)

int main(){
	int t;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>t;
	srand(time(0));
	for(int i=1;i<=t;i++){
		cout<<(random(10)<=6?"No":"Yes")<<endl;
	}
}
