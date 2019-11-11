#include <cstdio>
#include <cstring>

using namespace std;

int a,b;
int q[3010],r[3010];

int main()
{
    while(scanf("%d %d",&a,&b)==2 && b)
    {
        int q[3010],r[3010];
        q[0]=a/b;
        r[0]=a%b;
        q[1]=r[0]*10/b;
        r[1]=r[0]*10%b;
        int begin,end;
        begin=end=0;
        for(int i=2;;i++)
        {
            q[i]=r[i-1]*10/b;
            r[i]=r[i-1]*10%b;
            for(int k=1;k<i;k++)
                if(q[i]==q[k] && r[i]==r[k])
                {
                    end=i;begin=k;
                    break;
                }
            if(begin!=0)
                break;
        }
        printf("%d/%d = %d.",a,b,q[0]);
        for(int i=1;i<begin;i++)
        {
            if(i>50)
                break;
            printf("%d",q[i]);
        }
        printf("(");
        for(int i=begin;i<end;i++)
        {
            if(i>50)
                break;
            printf("%d",q[i]);
        }
        if(end>50)
            printf("...");
        printf(")\n   %d = number of digits in repeating cycle\n\n",end-begin);
    }
    return 0;
}
