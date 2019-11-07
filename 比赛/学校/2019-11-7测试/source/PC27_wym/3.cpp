#include<bits/stdc++.h>
using namespace std;
string ans;
bool prev;
long long qwq,original_qwq;
void proc_thousand(long long bas){
	switch(bas/1000){
		case 0:
			if(prev)
				ans.append("ling "),prev=false;
			break;
		case 1:
			ans.append("yi qian ");
			prev=true;
			break;
		case 2:
			ans.append("er qian ");
			prev=true;
			break;
		case 3:
			ans.append("san qian ");
			prev=true;
			break;
		case 4:
			ans.append("si qian ");
			prev=true;
			break;
		case 5:
			ans.append("wu qian ");
			prev=true;
			break;
		case 6:
			ans.append("liu qian ");
			prev=true;
			break;
		case 7:
			ans.append("qi qian ");
			prev=true;
			break;
		case 8:
			ans.append("ba qian ");
			prev=true;
			break;
		case 9:
			ans.append("jiu qian ");
			prev=true;	
			break;
	}
	bas%=1000;
	switch(bas/100){
		case 0:
			if(prev)
				ans.append("ling "),prev=false;
			break;
		case 1:
			ans.append("yi bai ");
			prev=true;
			break;
		case 2:
			ans.append("er bai ");
			prev=true;
			break;
		case 3:
			ans.append("san bai ");
			prev=true;
			break;
		case 4:
			ans.append("si bai ");
			prev=true;
			break;
		case 5:
			ans.append("wu bai ");
			prev=true;
			break;
		case 6:
			ans.append("liu bai ");
			prev=true;
			break;
		case 7:
			ans.append("qi bai ");
			prev=true;
			break;
		case 8:
			ans.append("ba bai ");
			prev=true;
			break;
		case 9:
			ans.append("jiu bai ");
			prev=true;	
			break;
	}
	bas%=100;
	switch(bas/10){
		case 0:
			if(prev)
				ans.append("ling "),prev=false;
			break;
		case 1:
			ans.append("yi shi ");
			prev=true;
			break;
		case 2:
			ans.append("er shi ");
			prev=true;
			break;
		case 3:
			ans.append("san shi ");
			prev=true;
			break;
		case 4:
			ans.append("si shi ");
			prev=true;
			break;
		case 5:
			ans.append("wu shi ");
			prev=true;
			break;
		case 6:
			ans.append("liu shi ");
			prev=true;
			break;
		case 7:
			ans.append("qi shi ");
			prev=true;
			break;
		case 8:
			ans.append("ba shi ");
			prev=true;
			break;
		case 9:
			ans.append("jiu shi ");
			prev=true;	
			break;
	}
	bas%=10;
	switch(bas){
		case 0:
			if(prev)
				ans.append("ling "),prev=false;
			break;
		case 1:
			ans.append("yi ");
			prev=true;
			break;
		case 2:
			ans.append("er ");
			prev=true;
			break;
		case 3:
			ans.append("san ");
			prev=true;
			break;
		case 4:
			ans.append("si ");
			prev=true;
			break;
		case 5:
			ans.append("wu ");
			prev=true;
			break;
		case 6:
			ans.append("liu ");
			prev=true;
			break;
		case 7:
			ans.append("qi ");
			prev=true;
			break;
		case 8:
			ans.append("ba ");
			prev=true;
			break;
		case 9:
			ans.append("jiu ");
			prev=true;	
			break;
	}
}
void proc_100million(long long bas){
	bas/=100000000;
	proc_thousand(bas);
}
void proc_10thousand(long long bas){
	bas/=10000;
	proc_thousand(bas);
}
int main(){
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>qwq;
	original_qwq=qwq;
	if(qwq>=100000000){
		proc_100million(qwq);
		ans.append("yi ");
	}
	qwq%=100000000;
	if(qwq>=10000){
		proc_10thousand(qwq);
		ans.append("wan ");
	}
	qwq%=10000;
	proc_thousand(qwq);
	if(ans[ans.length()-2]=='g'&&ans[ans.length()-3]=='n'&&ans[ans.length()-4]=='i'&&ans[ans.length()-5]=='l')
		ans.erase(ans.length()-5,5);
	if(original_qwq/1000000000==1||original_qwq/100000==1)
		ans.erase(0,3);
	for(int i=0;i<ans.length();++i){
		if((ans[i]=='l'&&ans[i+1]=='i'&&ans[i+2]=='n'&&ans[i+3]=='g'&&ans[i+5]=='w'&&ans[i+6]=='a'&&ans[i+7]=='n')||(ans[i]=='l'&&ans[i+1]=='i'&&ans[i+2]=='n'&&ans[i+3]=='g'&&ans[i+5]=='s'&&ans[i+6]=='h'&&ans[i+7]=='i')||(ans[i]=='l'&&ans[i+1]=='i'&&ans[i+2]=='n'&&ans[i+3]=='g'&&ans[i+5]=='y'&&ans[i+6]=='i'))
			ans.erase(i,5),i--;
	}
	cout<<ans;
	return 0;
}
