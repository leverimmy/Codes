#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
/*
#include<bits/stdc++.h>
using namespace std;
int main(){
	
}#include<bits/stdc++.h>
using namespace std;
int n,cnta,cntc,cntg,cntt;
char dna[20][2010],outp[2010];
int main(){
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>dna[i];
	}
	for(int i=0;i<strlen(dna[1]);++i){
		cnta=cntc=cntg=cntt=0;
		for(int j=1;j<=n;++j){
			switch(dna[j][i]){
				case 'A':
					++cnta;
					break;
				case 'C':
					++cntc;
					break;
				case 'G':
					++cntg;
					break;
				case 'T':
					++cntt;
					break;
			}
		}
		char tmp;
		int ans=0;
		if((ans=max(ans,cntt))==cntt)
			tmp='T';
		if((ans=max(ans,cntg))==cntg)
			tmp='G';
		if((ans=max(ans,cntc))==cntc)
			tmp='C';
		if((ans=max(ans,cnta))==cnta)
			tmp='A';
		outp[i]=tmp;
	}
	for(int i=0;i<strlen(dna[1]);++i)
		cout<<outp[i];
	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){#include<bits/stdc++.h>
using namespace std;
string s[110];
int main(){
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
	int n;
	cin>>n;
	s[1]="A";
	for(int i=2;i<=n;++i){
		s[i].append(s[i-1]);
		s[i].append(1,s[i-1][s[i-1].length()/2]+1);
		s[i].append(s[i-1]);
	}
	int len=s[n].length();
	for(int i=0;i<len;++i)
		putchar(s[n][i]);
	return 0;
}#include<bits/stdc++.h>
using namespace std;
int n;
char qwq[100010];
inline void outp(){
	for(int i=1;i<=n;++i)
		putchar(qwq[i]);
}
void rev(int l,int r){
	if(r-l+1<=1){
		return;
	}
	swap(qwq[l],qwq[r]);
	outp();
	putchar('\n');
	rev(l+1,r-1);
}
int main(){
	freopen("17.in","r",stdin);
	freopen("17.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",qwq+1);
	rev(1,n);
	putchar('\n'); 
	outp();
}#include<bits/stdc++.h>
using namespace std;
int a,b,lst;
int main(){
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=(b-a)/5;++i){
		if(i%2){
			for(int j=(i-1)*5;j<(i-1)*5+5;++j)
				cout<<j+a<<' ';
			cout<<endl;
		}
		else{
			for(int j=(i-1)*5+4;j>=(i-1)*5;--j)
				cout<<j+a<<' ';
			cout<<endl;
		}
	}
	if(((b-a)/5)%2==0){
		for(int i=((b-a)/5)*5+a;i<=b;++i)
			cout<<i<<' ';
	}
	else{
		for(int i=b;i>=((b-a)/5)*5+a;--i)
			cout<<i<<' ';
	}
	return 0;
}
	freopen("4.in","r",stdin);
	freopen("4.out","w",stdout);
	long long qwq;
	cin>>qwq;
	cout<<qwq+1;
	return 0;
}
*/
int main(){
//	freopen("10.in","r",stdin);
	freopen("14.out","w",stdout);
	Sleep(300);
	cout<<"5 2 1 3 4"<<endl;
	return 0;
}
