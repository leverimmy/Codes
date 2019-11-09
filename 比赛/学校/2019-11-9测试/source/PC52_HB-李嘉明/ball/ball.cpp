#include <cstdio>
#include <iostream>
using namespace std;

int n,x[200000],r[200000],i,j;
float curr[200000],mi,s;
	
float solve(float r1,int dis){
	float r2;
	int dis2=dis*dis;
	for(r2=0;;r2++){
		if((r1-r2)*(r1-r2)+dis*dis<(r1+r2)*(r1+r2)){  //dis2=25 r1-r2=1  r1+r2=1
			r2--;
			break;
		}
	}
	for(;;r2+=0.1){
		if((r1-r2)*(r1-r2)+dis*dis<(r1+r2)*(r1+r2)){
			r2-=0.1;
			break;
		}
	}
	for(;;r2+=0.01){
		if((r1-r2)*(r1-r2)+dis*dis<(r1+r2)*(r1+r2)){
			r2-=0.01;
			break;
		}
	}
	for(;;r2+=0.001){
		if((r1-r2)*(r1-r2)+dis*dis<(r1+r2)*(r1+r2)){
			r2-=0.001;
			break;
		}
	}
	for(;;r2+=0.0001){
		if((r1-r2)*(r1-r2)+dis*dis<(r1+r2)*(r1+r2)){
			r2-=0.0001;
			break;
		}
	}
	for(;;r2+=0.00001){
		if((r1-r2)*(r1-r2)+dis*dis<(r1+r2)*(r1+r2)){
			r2-=0.00001;
			break;
		}
	}
	return r2;
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x[i]>>r[i];
	}
	curr[0]=r[0];
	printf("%.3f\n",curr[0]);
	for(i=1;i<n;i++){
		mi=999999999;
		for(j=0;j<i;j++){
			s=solve(curr[j],x[i]-x[j]);
			if(s<mi){
				mi=s;
			}
		}
		curr[i]=mi;
		if(curr[i]>r[i])curr[i]=r[i];
		printf("%.3f\n",curr[i]);
	}
	return 0;
}
