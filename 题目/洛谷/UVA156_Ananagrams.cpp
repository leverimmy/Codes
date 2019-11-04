#include <cstdio>
#include <cctype>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

map <string,int> _count;
vector <string> words;
string init(const string& s)
{
	string ans=s;
	for(int i=0;i<ans.length();i++)
		ans[i]=tolower(ans[i]);
	sort(ans.begin(),ans.end());
	return ans;
}

int main()
{
	string s;
	while(cin>>s)
	{
		if(s[0]=='#')
			break;
		words.push_back(s);
		string re=init(s);
		if(!_count.count(re))
			_count[re]=0;
		_count[re]++;
	}
	vector <string> ans;
	for(int i=0;i<words.size();i++)
		if(_count[init(words[i])]==1)
			ans.push_back(words[i]);
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<"\n";
	return 0;
}