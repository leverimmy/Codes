#include<iostream>
#include<cmath>

using namespace std;
char a[6][6];
int n;
int main(){
	freopen("out.ans","w",stdout);
	cin>>n;
	for(int i=0;i<5;i++){
		cin>>a[i];
	}
	cout<<"if(";
	for(int i=0;i<5;i++){
		for(int j=0;j<3;j++){
			cout<<"a[j+"<<i<<"][i+"<<j<<"]=='"<<a[i][j]<<"'&&";
		}
	}
	printf("\b\b\){\n		    cout<<%d;\n		    i+=3;\n		    break;\n		}",n);
	return 0;
}