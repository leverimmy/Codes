#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int sum[100001];
int seq[100001];
deque<int>q;
string solve(int l,int r){
	if(l&&sum[r]-sum[l-1]==0){
		string k;
		for(int i=l;i<=r;i++){
			k+=s[i];
		}
		return k;
	}
	int fir=l;
	string pre;
	while(isalpha(s[fir]))pre+=s[fir],fir++;
	if(seq[fir]==r){
		return min(solve(fir+1,r-1),pre)+'['+max(solve(fir+1,r-1),pre)+']';
	}
	string ss[3];
	string k1=pre+'['+solve(fir+1,seq[fir]-1)+"]["+solve(seq[fir]+1,r-1)+']';
	string k2=solve(seq[fir]+1,r-1)+'['+solve(fir+1,seq[fir]-1)+'['+pre+"]]";
	string k3=solve(seq[fir]+1,r-1)+'['+pre+'['+solve(fir+1,seq[fir]-1)+"]]";
	return min(k1,min(k1,k3));
}
int main(){
	//freopen("subscript.in","r",stdin);
	//freopen("subscript.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>s;
		for(int i=0;i<s.size();i++){
			sum[i]=i==0?(s[i]=='['||s[i]==']'):sum[i-1]+(s[i]=='['||s[i]==']');
			if(s[i]=='['){
				q.push_back(i);
			}
			else if(s[i]==']'){
				seq[q.back()]=i;
				q.pop_back();
			}
		}
		cout<<solve(0,s.size()-1)<<'\n';
	}
	return 0;
}
