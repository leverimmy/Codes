#include<bits/stdc++.h>
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
}
