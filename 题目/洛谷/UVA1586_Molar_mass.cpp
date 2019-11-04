#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

int n,len;
double ans;
char s[1111];

void count()
{
    double num=0;
    double c=0,n=0,o=0,h=0;
    for(int i=0;i<=len-1;i++)
    {
        if(i==len-1)
        {
            if(s[i]=='C')   c++;
            else if(s[i]=='N')  n++;
            else if(s[i]=='H')  h++;
            else if(s[i]=='O')  o++;
        }
        else
        {
            switch(s[i])
            {
                case 'C':
                {
                    while(s[i+1]>='0' && s[i+1]<='9')
                    {
                        num*=10;
                        num+=s[i+1]-'0';
                        i++;
                    }
                    if(num==0) ++num;
                    c+=num;
                    break;
                }
                case 'H':
                {
                    while(s[i+1]>='0' && s[i+1]<='9')
                    {
                        num*=10;
                        num+=s[i+1]-'0';
                        i++;
                    }
                    if(num==0) ++num;
                    h+=num;
                    break;
                }

                case 'O':
                {
                    while(s[i+1]>='0' && s[i+1]<='9')
                    {
                        num*=10;
                        num+=s[i+1]-'0';
                        i++;
                    }
                    if(num==0) ++num;
                    o+=num;
                    break;
                }
                case 'N':
                {
                    while(s[i+1]>='0' && s[i+1]<='9')
                    {
                        num*=10;
                        num+=s[i+1]-'0';
                        i++;
                    }
                    if(num==0) num++;
                    n+=num;
                    break;
                }
            }
            num=0;
        }
    }
    ans=c*12.01+h*1.008+o*16.00+n*14.01;
}

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        len=strlen(s);
        count();
        printf("%.3f\n",ans);
    }
    return 0;
}