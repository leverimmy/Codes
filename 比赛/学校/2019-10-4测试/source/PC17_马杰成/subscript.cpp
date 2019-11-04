#include<bits/stdc++.h>
using namespace std;
int t;

int main(){
	freopen("subscript.in","r",stdin);
	freopen("subscript.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		string s;
		cin>>s;
		int len=s.length();
		if(len<=2){
			cout<<s<<endl;
		}
		else if(len<=5){
			int pos1=-1,pos2=-1;
			for(int i=0;i<len;i++){
				if(s[i]=='['){
					pos1=i;
				}
				if(s[i]==']'){
					pos2=i;
				}
			}
			if(pos1==-1 && pos2==-1){
				cout<<s<<endl;
			}
			else{
				char s1[10],s2[10];
				for(int i=0;i<pos1;i++){
					s1[i]=s[i];
				}
				int p=0;
				for(int i=pos1+1;i<pos2;i++){
					s2[p]=s[i];
					p++;
				}
				if(strcmp(s1,s2)==1 && pos1>=p){
					for(int i=0;i<p;i++){
						printf("%c",s2[i]);
					}					
					cout<<"[";
					for(int i=0;i<pos1;i++){
						printf("%c",s1[i]);
					}		
					cout<<"]"<<endl;			
				}
				else{
					for(int i=0;i<pos1;i++){
						printf("%c",s1[i]);
					}					
					cout<<"[";
					for(int i=0;i<p;i++){
						printf("%c",s2[i]);
					}		
					cout<<"]"<<endl;						
				}
			} 
		}
	}
}
