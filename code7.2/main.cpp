#include <stdio.h>
long long F[21]; //数值较大选用long long
int main ()
{
    F[1] = 0;
    F[2] = 1; //初始值
    for (int i = 3; i <= 20; i ++)
        F[i] = (i - 1) * F[i - 1] + (i - 1) * F[i - 2]; //递推求得数列每一个数字
    int n;
    while (scanf ("%d",&n) != EOF)
    {
        printf("%lld\n",F[n]); //输出
    }
    return 0;
}
