#include<bits/stdc++.h>
using namespace std;
const int maxq=100010;
struct node{
	int op,x1,y1,x2,y2,col,pos;
}in[maxq];
bool vis[maxq];
int a[1010][1010];
int n,k,m;
int ok[1010][1010];
int rem[maxq];
int rem_cnt;
inline int read(){
	char ch=getchar();
	int ans=0,f=1;
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
int main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	n=read();k=read();m=read();
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=m;i++){
		char ch[20];
		scanf("%s",ch);
		if(ch[0]=='P'){
			in[i].op=1;
			in[i].col=read();in[i].x1=read();in[i].y1=read();in[i].x2=read();in[i].y2=read();
			in[i].x1++;in[i].x2++;in[i].y1++;in[i].y2++;
		}
		if(ch[0]=='S'){
			in[i].pos=read();
			in[i].op=2;
			rem[++rem_cnt]=i;
		} 
		if(ch[0]=='L'){
			in[i].pos=read();
			in[i].op=3;
		}
	}
	for(int i=m;i>=1;i--){
		if(in[i].op==3){
			i=rem[in[i].pos];
		}
		else if(in[i].op==1){
			vis[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=1;
		}
	}
	for(int i=m;i>=1;i--){
		if(vis[i]){
			int cnt_n=0,c=0;
			for(int j=in[i].x1;j<=in[i].x2;j++){
				cnt_n++;
				if(cnt_n%2==1) c=0;
				else c=1;
				for(int k=in[i].y1;k<=in[i].y2;k++){
					if(c%2==0 && !ok[j][k]){
						a[j][k]=in[i].col;
						ok[j][k]=1;
					}
					c++;
				}
			}
		}
	}	

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

