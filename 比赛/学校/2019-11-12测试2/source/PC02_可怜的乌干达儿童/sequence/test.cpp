#include <bits/stdc++.h>

int h[]={0,10,11,15,16};

int main(){
	printf("%d",std::upper_bound(h+1,h+4+1,16)-(h+1));
}
