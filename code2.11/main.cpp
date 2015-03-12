//以下程序只能实现 奇数

//#include <stdio.h>
//
//int main()
//{
//    int outPutBuf[82][82];
//    char a,b;
//    int n;
//    bool firstCase = true;
//    while(scanf("%d %c %c",&n,&a,&b)==3)
//    {
//        if(firstCase==true)
//        {
//            firstCase=false;
//        }
//        else printf("\n");
//        for(int i=1,j=1;i<=n;i+=2,j++)
//        {
//            int x=n/2+1;
//            int y=x;
//            x-=(j-1);
//            y-=(j-1);
//            char c=(j%2==1?a:b);
//            for(int k=1; k<=i; k++)
//            {
//                outPutBuf[x+k-1][y]=c;
//                outPutBuf[x][y+k-1]=c;
//                outPutBuf[x+i-1][y+k-1]=c;
//                outPutBuf[x+k-1][y+i-1]=c;
//            }
//        }
//        if(n!=1)//当n为1时不需要此步骤
//        {
//            outPutBuf[1][1]=' ';
//            outPutBuf[n][1]=' ';
//            outPutBuf[1][n]=' ';
//            outPutBuf[n][n]=' ';
//        }
//        for(int i=1; i<=n; i++)
//        {
//            for(int j=1; j<=n; j++)
//            {
//                printf("%c",outPutBuf[i][j]);
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}



//以下程序可以同时实现 奇数和偶数

#include <stdio.h>

int main()
{
    int n;
    char a,b;
    int flag=0;

    char buf[82][82];       //Buffer
    for(int i=0; i<82;i++)  //Initialize
    {
        for(int j=0; j<82; j++)
        {
            buf[i][j]=0;
        }
    }

    while(scanf("%d %c %c",&n,&a,&b)!=EOF)
    {
        int central=(n-1)/2;
        for(int i=0; i<=central; i++)
        {
            if(flag==0)
            {
                //buf[i][i]=b;
                //buf[i][n-i-1]=b;
                for(int j=i; j<=n-i-1; j++)
                {
                    buf[i][j]=b;
                    buf[j][i]=b;
                    buf[n-1-i][j]=b;
                    buf[j][n-1-i]=b;
                }
                flag=1;
            }
            else
            {
                //buf[i][i]=a;
                //buf[i][n-i-1]=a;
                for(int j=i; j<=n-i-1; j++)
                {
                    buf[i][j]=a;
                    buf[j][i]=a;
                    buf[n-1-i][j]=a;
                    buf[j][n-1-i]=a;
                }
                flag=0;
            }
        }
        buf[0][0]=' ';
        buf[0][n-1]=' ';
        buf[n-1][0]=' ';
        buf[n-1][n-1]=' ';

        for(int i=0; i<n;i++)
        {
            for(int j=0; j<n; j++)
            {
                printf("%c",buf[i][j]);
            }
            printf("\n");
        }
    }
}




