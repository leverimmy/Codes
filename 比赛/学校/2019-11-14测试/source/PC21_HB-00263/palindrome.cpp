#include<bits/stdc++.h>
using namespace std;
char s[5010];
short len;
short zzy[5010][5010];
int cnt[5010];
inline bool chck(int l,int r){
	int tlen=(r-l+1)/2;
	for(int i=1;i<=tlen;++i)
		if(s[i+l-1]!=s[r-i+1])
			return false;
	return true;
}
int main(){
	freopen("palindrome.in","r",stdin);
	freopen("palindrome.out","w",stdout);
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;++i){
		for(int j=1;j<=len;++j){
			if(j+i-1>len)
				break;
			if(chck(j,j+i-1)){
				zzy[j][j+i-1]=zzy[j][j+(i/2)-1]+1;
//				cnt[zzy[j][j+i-1]]++,
//				cout<<j<<' '<<j+i-1<<' '<<zzy[j][j+i-1]<<endl;
			}
		}
	}
	for(int i=1;i<=len;++i)
		for(int j=i;j<=len;++j)
			for(int k=1;k<=zzy[i][j];++k)
				cnt[k]++;
	for(int i=1;i<=len;++i)
		printf("%d ",cnt[i]);
	return 0;
}
