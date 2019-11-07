#include<bits/stdc++.h>
using namespace std;
int a[10];
inline bool check(int x){
	return a[1]==x||a[2]==x;
}
int main(){
	freopen("14.in","r",stdin);
	freopen("14.out","w",stdout);
	for(int i=1;i<=5;i++) a[i]=i;
	do{
		if(a[2]==5||a[3]==5) continue;
		if(check(1)) {
			if(a[1]!=5) continue; 
		}else {
			if(a[1]==5) continue;
		}
		if(check(2)) {
			if(a[2]!=2) continue; 
		}else {
			if(a[2]==2) continue;
		}
		if(check(3)) {
			if(a[5]!=1) continue; 
		}else {
			if(a[5]==1) continue;
		}
		if(check(4)) {
			if(a[1]==3) continue; 
		}else {
			if(a[1]!=3) continue;
		}
		if(check(5)) {
			if(a[1]!=4) continue; 
		}else {
			if(a[1]==4) continue;
		}
		for(int i=1;i<=5;i++) 
			for(int j=1;j<=5;j++)
				if(i==a[j]) cout<<j<<' ';
	}while(next_permutation(a+1,a+6));
	return 0;
}
