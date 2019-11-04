#include <iostream>
#include <cstdio>
using namespace std;
string a[3];//始终为数组中的第二小的值减去最小值
long long num=0;
string min1,min2;
string maxx(string a,string b){
	int lena=a.length();
	int lenb=b.length();
	if((lena-lenb)>0){
		return a;
	}
	if(lena<lenb){
		return b;
	}
	for(int i=0;i<lena;i++){
		if(a[i]>b[i]){
			return a;
		}
		if(a[i]<b[i]){
			return b;
		}
	}
	return a;
}
string minn(string a,string b){
	int lena=a.length();
	int lenb=b.length();
	if((lena-lenb)>0){
		return b;
	}
	if(lena<lenb){
		return a;
	}
	for(int i=0;i<lena;i++){
		if(a[i]>b[i]){
			return b;
		}
		if(a[i]<b[i]){
			return a;
		}
	}
	return a;
} 
string sub(string str1,string str2)//高精度减法		大的减小的 
{
    string str;
    int tmp=str1.length()-str2.length();
    int cf=0;
    for(int i=str2.length()-1;i>=0;i--)
    {
        if(str1[tmp+i]<str2[i]+cf)
        {
            str=char(str1[tmp+i]-str2[i]-cf+'0'+10)+str;
            cf=1;
        }
        else
        {
            str=char(str1[tmp+i]-str2[i]-cf+'0')+str;
            cf=0;
        }
    }
    for(int i=tmp-1;i>=0;i--)
    {
        if(str1[i]-cf>='0')
        {
            str=char(str1[i]-cf)+str;
            cf=0;
        }
        else
        {
            str=char(str1[i]-cf+10)+str;
            cf=1;
        }
    }
    str.erase(0,str.find_first_not_of('0'));//去除结果中多余的前导0
    return str;
}

int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>a[1]>>a[2];
	min2=maxx(a[1],a[2]);
	min1=minn(a[1],a[2]);
	while(min1!=""){
		num++;
		string tmp;
		tmp=sub(min2,min1);
		min2=maxx(min1,tmp);
		min1=minn(min1,tmp);
	}
	cout<<num+1;
	return 0;
}
