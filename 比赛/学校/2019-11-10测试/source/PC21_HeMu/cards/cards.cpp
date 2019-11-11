#include<bits/stdc++.h>
using namespace std;
long long a,b,ans=-2147483647;
bool flag;
char stat='o';
vector<int>qwq,tmp;
void dfsb(long long typ,long long val);
void dfsa(long long typ,long long val){
	if(!b){
		qwq.push_back(a);
		val+=typ*a*a;
		if(ans<val){
			if(flag)
				stat='x';
//			cout<<"!!!"<<endl;
			ans=val,
			tmp.clear();
			for(int i=0;i<qwq.size();++i)
				tmp.push_back(qwq[i]);
		}
		qwq.pop_back();
		return;
	}
	for(long long i=1;i<=a;++i){
		val+=typ*i*i;
		a-=i;
		qwq.push_back(i);
		dfsb(-1,val);
		val-=typ*i*i; 
		a+=i;
		qwq.pop_back();
	}
}
void dfsb(long long typ,long long val){
	if(!a){
		val+=typ*b*b;
		qwq.push_back(b);
		if(ans<val){
			if(flag)
				stat='x';
//			cout<<"!!!"<<endl;
			ans=val,
			tmp.clear();
			for(int i=0;i<qwq.size();++i)
				tmp.push_back(qwq[i]);
		}
		qwq.pop_back();
		return;
	}
	for(long long i=1;i<=b;++i){
		val+=typ*i*i;
		b-=i;
		qwq.push_back(i);
		dfsa(1,val);
		b+=i;
		qwq.pop_back();
	}
}
int main(){
	freopen("cards.in","r",stdin);
	freopen("cards.out","w",stdout);
	cin>>a>>b;
	dfsa(1,0);
	flag=true;
	dfsb(-1,0);
	cout<<ans<<endl;
//	char stat='o';
	for(int i=0;i<tmp.size();++i){
		for(int j=1;j<=tmp[i];++j)
			cout<<stat;
		if(stat=='o')
			stat='x';
		else
			stat='o';
	}
}
