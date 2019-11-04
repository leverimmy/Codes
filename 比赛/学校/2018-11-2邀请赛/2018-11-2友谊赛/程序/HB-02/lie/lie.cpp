#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
struct node{
	int h;
	int l;
}duiwu[100010];
int m[100010];
int ans=0;
int k=0;
bool cmp(node a,node b){
	int k1=a.h+a.l;
	int k2=b.h+b.l;
	return k1>k2;
}
int main(){
	freopen("lie.in","r",stdin);
	freopen("lie.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int	a,b;
		cin>>a>>b;
		if(a+b>n-1){
			ans++;
			continue;
		}
		duiwu[++k].h=a;
		duiwu[k].l=b;
}	
	sort(duiwu+1,duiwu+k+1,cmp);
	for(int i=1;i<=k;i++){
		int flag=0,ca=0;
		for(int j=duiwu[i].h+1;j<=n-duiwu[i].l;j++){
			if(m[j]){
				flag=1;
				ca=j;
				break;
			}
 		}
		int kk=m[ca];
 		for(int j=duiwu[i].h+1;j<=n-duiwu[i].l;j++){
 			 if(m[j]!=kk) {
			  flag++;break;
			 	}
			 }
 		if(flag==2){
 			ans++;
 	//		cout<<i<<endl;
 			break;
		 }
 		for(int j=duiwu[i].h+1;j<=n-duiwu[i].l;j++){
 			m[j]=n-i+1;
		}
	//	for(int i=1;i<=n;i++)
	//		cout<<m[i]<<" ";
	//	cout<<endl; 
	}
	cout<<ans<<endl;
	return 0;
}
