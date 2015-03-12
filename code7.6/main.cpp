#include <stdio.h>
#define OFFSET 2000 //因为柑橘重量差存在负数的情况,即第一堆比第二堆轻,所以在计算重量差对应的数组下标时加上该偏移值,使每个重量差对应合法的数组下标
int dp[101][4001]; //保存状态
int list[101]; //保存柑橘数量
#define INF 0x7fffffff //无穷

int main ()
{
    int T;
    int cas = 0; //处理的Case数,以便输出
    scanf ("%d",&T); //输入要处理的数据组数
    while (T -- != 0)   //T次循环
    {
        int n;
        scanf ("%d",&n);
        bool HaveZero = false; //统计是否存在重量为0的柑橘
        int cnt = 0; //计数器,记录共有多少个重量非零的柑橘
        for (int i = 1; i <= n; i ++) //输入n个柑橘重量
        {
            scanf ("%d",&list[++ cnt]);
            if (list[cnt] == 0)   //若当前输入柑橘重量为0
            {
                cnt --; //去除这个柑橘
                HaveZero = true; //并记录存在重量为0的柑橘
            }
        }
        n = cnt;
        for (int i = -2000; i <= 2000; i ++)
        {
            dp[0][i + OFFSET] = -INF;
        } //初始化,所有dp[0][i]为负无穷。注意要对重量差加上OFFSET后读取或调用
        dp[0][0 + OFFSET] = 0; //dp[0][0]为0
        for (int i = 1; i <= n; i ++) //遍历每个柑橘
        {
            for (int j = -2000; j <= 2000; j ++) //遍历每种可能的重量差
            {
                int tmp1 = -INF,tmp2 = -INF; //分别记录当前柑橘放在第一堆或第二堆时转移得来的新值,若无法转移则为-INF
                if (j + list[i] <= 2000 && dp[i - 1][j + list[i] + OFFSET] != -INF)   //当状态可以由放在第一堆转移而来时
                {
                    tmp1 = dp[i - 1][j + list[i] + OFFSET] + list[i]; //记录转移值
                }
                if (j - list[i] >= -2000 && dp[i - 1][j - list[i] + OFFSET] != -INF)   //当状态可以由放在第二堆转移而来时
                {
                    tmp2 = dp[i - 1][j - list[i] + OFFSET] + list[i]; //记录该转移值
                }
                if (tmp1 < tmp2)
                {
                    tmp1 = tmp2;
                } //取两者中较大的那个,保存至tmp1
                if (tmp1 < dp[i - 1][j + OFFSET])   //将tmp1与当前柑橘不放入任何堆即状态差不发生改变的原状态值比较，取较大的值保存至tmp1
                {
                    tmp1 = dp[i - 1][j + OFFSET];
                }
                dp[i][j + OFFSET] = tmp1; //当前值状态保存为三个转移来源转移得到的新值中最大的那个
            }
        }
        printf("Case %d: ",++ cas);//按题目输出要求输出
        if (dp[n][0 + OFFSET] == 0)   //dp[n][0]为0
        {
            puts( HaveZero == true ? "0" : "-1");//根据是否存在重量为0的柑橘输出0或-1
        }
        else printf("%d\n",dp[n][0 + OFFSET] / 2); //否则输出dp[n][0] / 2
    }
    return 0;
}
