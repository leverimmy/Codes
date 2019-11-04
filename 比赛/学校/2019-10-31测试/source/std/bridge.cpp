#include<bits/stdc++.h>

using namespace std;
const int oo=1000000;
int m[55][55];
bool vis[55];
int n;

int maxDifference(vector <string> a, int d)
{
  n=a.size();
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(a[i][j]=='Y')
        m[i][j]=1;
      else m[i][j]=oo;
  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        m[i][j]=min(m[i][j],m[i][k]+m[k][j]);
  int ans=0;
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      ans=max(ans,m[i][j]);
  if(ans==oo)return -1;
  return ans*d;
}

int main()
{
	freopen("bridge.in","r",stdin);
	freopen("bridge.out","w",stdout);	
    int casT;
    cin>>casT;
    while(casT--)
    {
        vector<string> ST;
        string tmp;
        int n,d;
        cin>>n>>d;
        while(n--){
            cin>>tmp;
            ST.push_back(tmp);
        }
        cout<<maxDifference(ST,d)<<endl;
    }
    return 0;
}
