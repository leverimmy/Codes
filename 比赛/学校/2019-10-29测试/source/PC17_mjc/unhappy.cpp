#include<bits/stdc++.h>
using namespace std;
vector<int > a;
int delta;
int leave;
int c[210010];
void getin(int x){
	vector <int> :: iterator it;
	it=lower_bound(a.begin(),a.end(),x); 
	a.insert(it,x);	
}
void del(int x){
	int pos=lower_bound(a.begin(),a.end(),x)-a.begin();
	memset(c,0,sizeof(c));
	int cnt=0;
	for(int i=pos;i<a.size();i++){
		c[cnt]=a[i];
		cnt++;
	}
	leave+=pos;
	a.clear();
	for(int i=0;i<cnt;i++){
		a.push_back(c[i]);
	}
}
void kth(int x){
	if(x>a.size()) printf("-1\n");
	else 
		printf("%d\n",delta+a[a.size()-x]);
}
int n,ming;
void debug(){
	cout<<"delta:"<<" "<<delta<<endl;
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main(){
	freopen("unhappy.in","r",stdin);
	freopen("unhappy.out","w",stdout);
	scanf("%d%d",&n,&ming);
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(ch=='I'){
			int x;
			scanf("%d",&x);
			if(x>=ming){
				getin(x-delta);
			}
		}
		if(ch=='A'){
			int x;
			scanf("%d",&x);
			delta+=x;
		} 
		if(ch=='S'){
			int x;
			scanf("%d",&x);
			delta-=x;
			del(ming-delta);
		}
		if(ch=='F'){
			int x;
			scanf("%d",&x);
			kth(x);
		}
//		debug();
	}
	printf("%d\n",leave);
}
