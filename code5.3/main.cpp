#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 101
int Tree[N];

int findRoot(int x)   //查找代表集合的树的根结点
{
    if (Tree[x] == -1) return x;
    else
    {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

struct Edge   //边结构体
{
    int a , b; //边两个顶点的编号
    int cost; //该边的权值
    bool operator < (const Edge &A) const   //重载小于号使其可以按照边权从小到大排列
    {
        return cost < A.cost;
    }
} edge[6000];

int main ()
{
    freopen("C:\\Users\\LENOVO\\Desktop\\input.txt","r",stdin);
    int n;
    while (scanf ("%d",&n) != EOF && n != 0)
    {
        for (int i = 1; i <= n * (n - 1) / 2; i ++)
        {
            scanf ("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
        } //输入
        sort(edge + 1,edge + 1 + n * (n - 1) / 2); //按照边权值递增排列所有的边

        for (int i = 1; i <= n; i ++)
            Tree[i] = -1; //初始时所有的结点都属于孤立的集合

        int ans = 0; //最小生成树上边权的和,初始值为0
        for (int i = 1; i <= n * (n - 1) / 2; i ++) //按照边权值递增顺序遍历所有的边
        {
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b); //查找该边两个顶点的集合信息
            if (a != b)   //若它们属于不同集合,则选用该边
            {
                Tree[a] = b; //合并两个集合
                ans += edge[i].cost; //累加该边权值
            }
        }
        printf("%d\n",ans); //输出
        for(int i=1; i<=n; i++)
        {
            printf("Tree[%d]: %d\n",i,Tree[i]);
        }
    }
    fclose(stdin);
    return 0;
}
