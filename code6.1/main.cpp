#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int x,y,z;
        for(x=0; x<=100; x++)
        {
            for(y=0; y<=100-x; y++)
            {
                z=100-x-y;
                if(3*n-(15*x+9*y+z)>=0)
                {
                    printf("x=%d,y=%d,z=%d\n",x,y,z);
                }
            }
        }
    }
    return 0;
}
