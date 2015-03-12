#include <stdio.h>
long long F[91];//F数组保存数列的每一个值，由于数值过大，我们需要使用long long类型
int main ()
{
    F[1] = 1;
    F[2] = 2; //数列初始值
    for (int i = 3; i <= 90; i ++)
        F[i] = F[i - 1] + F[i - 2]; //递推求得数列的每一个数字
    int n;
    while (scanf ("%d",&n) != EOF)   //输入
    {
        printf("%lld\n",F[n]); //输出相应的数列数字
    }
    return 0;
}
