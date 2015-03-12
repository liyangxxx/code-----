#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 0x7fffffff //预定义最大的int取值为无穷

int list[2001]; //保存每个物品重量
int dp[1001][2001]; //保存每个状态

int main ()
{
    int n, k;
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        for (int i=1; i<=n; i++)
        {
            scanf ("%d",&list[i]);
        } //输入

        sort(list+1, list+1+n); //使所有物品按照重量递增排序
        for (int i=1; i<=n; i++) //初始值
            dp[0][i]=0;

        for (int i=1; i<=k; i++) //递推求得每个状态
        {
            for (int j=2*i; j<=n; j++)
            {
                if (j>2*i) //若j>2*i则表明,最后两个物品可以不配对,即前j-1件物品足够配成i对，dp[i][j]可以由dp[i][j - 1]转移而来，其值先被设置为dp[i][j - 1]
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = INF; //若j == 2 * i,说明最后两件物品必须配对,否则前j件物品配不成i对,所以其状态不能由dp[i][j - 1]转移而来，dp[i][j]先设置为正无穷
                if (dp[i][j] > dp[i - 1][j - 2] + (list[j] - list[j - 1]) * (list[j] - list[j - 1])) //若dp[i][j]从dp[i-1][j-2]转移而来时，其值优于之前确定的正无穷或者由dp[i][j - 1]转移而来的值时，更新该状态
                    dp[i][j] = dp[i - 1][j - 2] + (list[j] - list[j - 1]) * (list[j] - list[j - 1]); //更新
            }
        }
        printf("%d\n",dp[k][n]); //输出
    }
    return 0;
}
