#include <stdio.h>
//#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return( a>b );
}

int main()
{
    int n;
    int buf[100];
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d",&buf[i]);
        }
        sort(buf,buf+n,cmp);
        for(int i=0; i<n; i++)
        {
            //printf("%d ",buf[i]);
        }
    }
    return 0;
}
