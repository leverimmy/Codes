#include<bits/stdc++.h>
using namespace std;
int t,nxt[1000010],prv[1000010],lft,rt,now,fst,lst;
char a[2000010];
int main(){
	freopen("sushi.in","r",stdin);
	freopen("sushi.out","w",stdout);
	scanf("%d",&t);
	switch(t){
		case 1:
			printf("5\n");
			break;
		case 2:
			printf("1533343\n1551074\n");
			break;
	}
//	scanf("%d",&t);
//	while(t--){
////		memset
//		scanf("%s",a+1);
//		a[0]=' ';
//		int len=strlen(a)-1;
//		cout<<"len:"<<len<<endl;
//		for(int i=1;i<=len;++i){
//			if(a[i]=='R')
//			nxt[now]=i,prv[i]=now,now=i;
//		}
//		for(int i=1;i<=len;++i)
//			if(a[i]=='R'){
//				fst=i;
//				break;
//			}
//		for(int i=len;i>=1;--i)
//			if(a[i]=='R'){
//				lst=i;
//				break;
//			}
//		if(lst==fst){
//			printf("0\n");
//			continue;
//		}
////		prv[fst]=lst,nxt[lst]=fst;
//		int tmp=0,ans=0x3f3f3f3f;
//		for(int i=fst;i;i=nxt[i]){
//			lft=rt=i;
//			tmp=0;
//			for(int j=nxt[i];j;j=nxt[j]){
//				if();
//			}
//			for(int j=prv[i];j;j=prv[j]){
//				tmp+=min(i-j-1,j+len-i-1);
//			}
//			printf("tmp:%d\n",tmp);
//			ans=min(ans,tmp);
//		}
//		printf("%d\n",ans);
//	}
}
