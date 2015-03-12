#include <stdio.h>
#include <string.h>
int dp[101][101];
int max(int a,int b)
{
    return a > b ? a : b;    //取最大值函数
}

int main ()
{
    char S1[101],S2[101];
    while (scanf ("%s%s",S1,S2) != EOF)   //输入
    {
        int L1 = strlen(S1);
        int L2 = strlen(S2); //依次求得两个字符串的长度

        for (int i = 0; i <= L1; i ++)
            dp[i][0] = 0;
        for (int j = 0; j <= L2; j ++)
            dp[0][j] = 0; //初始值

        for (int i = 1; i <= L1; i ++)
        {
            for (int j = 1; j <= L2; j ++) //二重循环依次求得每个dp[i][j]值
            {
                if (S1[i - 1] != S2[j - 1]) //因为字符串数组下标从0开始，所以第i个字符位置为S1[i-1],若当前两个字符不相等
                    dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]); //dp[i][j]为dp[i][j - 1] 和 dp[i - 1][j]中较大的一个
                else dp[i][j] = dp[i - 1][j - 1] + 1; //若它们相等，则dp[i][j]比dp[i - 1][j - 1]再加一
            }
        }
        printf("%d\n",dp[L1][L2]); //输出答案
    }
    return 0;
}
