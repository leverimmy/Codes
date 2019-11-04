#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int num[5],ans[14][14][14][14][14];
int result;
int t;

void deal()
{
    for(int a=1;a<=13;a++)
        for(int b=1;b<=13;b++)
            for(int c=1;c<=13;c++)
                for(int d=1;d<=13;d++)
                    for(int e=1;e<=13;e++)
                    {
                        if(a<5&&b<5&&c<5&&d<5&&e<5&&a+b+c+d+e<=10)
                        {
                            ans[a][b][c][d][e]=60;
                        }
                        else if(a>10&&b>10&&c>10&&d>10&&e>10)
                        {
                            ans[a][b][c][d][e]=50;
                        }
                        else if((a==b&&b==c&&c==d)||(a==b&&b==c&&c==e)
                              ||(a==b&&b==d&&d==e)||(b==c&&c==d&&d==e)||(a==c&&c==d&&d==e))
                        {
                            ans[a][b][c][d][e]=40;
                        }
                        else
                        {
                            int ma=min(10, a);
                            int mb=min(10, b);
                            int mc=min(10, c);
                            int md=min(10, d);
                            int me=min(10, e);
                            if((ma+mb+mc)%10==0||(ma+mb+md)%10==0||(ma+mb+me)%10==0
                             ||(ma+mc+md)%10==0||(ma+mc+me)%10==0||(ma+md+me)%10==0
                             ||(mb+mc+md)%10==0||(mb+mc+me)%10==0||(mb+md+me)%10==0
                             ||(mc+md+me)%10==0)
                            {
                                int sum=ma+mb+mc+md+me;
                                if(sum%10==0)
                                    ans[a][b][c][d][e]=30;
                                else if(sum%10<7)
                                    ans[a][b][c][d][e]=sum%10;
                                else
                                    ans[a][b][c][d][e]=(sum%10)*2;
                            }
                            else
                                ans[a][b][c][d][e]=0;
                        }
                    }
}

int main()
{
    freopen("niuniu.in","r",stdin);
    freopen("niuniu.out","w",stdout);

    scanf("%d",&t);
    //cout<<"t="<<t<<endl;
    deal();
    for(int i=1;i<=t;i++)
    {
    	result=0;
        scanf("%d%d%d%d",&num[1],&num[2],&num[3],&num[4]);
        for(int j=1;j<=13;j++)
        {
            result+=ans[num[1]][num[2]][num[3]][num[4]][j];
        }
        result=(result/13.0)+0.5;
        printf("%d\n",result);
        //printf("***\n");
    }
    return 0;
}
