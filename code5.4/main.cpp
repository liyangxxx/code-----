#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct node
{
    double x;
    double y;
};
node point[100];//100个点

struct link
{
    int num1;
    int num2;
    node node1;
    node node2;
    double cost;

    bool operator < (const link &A) const
    {
        return cost<A.cost;
    }
};
link vertex[4950];

int Tree[100];

int findroot(int x)
{
    if(Tree[x]==-1)
    {
        return x;
    }
    else
    {
        return findroot(Tree[x]);
    }
}

int main()
{
    freopen("C:\\Users\\LENOVO\\Desktop\\input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)   //输入点的信息
    {
        Tree[i]=-1;   //初始化根列表
        scanf("%lf %lf",&point[i].x,&point[i].y);
    }
    int k=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            vertex[k].num1=i;
            vertex[k].num2=j;
            vertex[k].node1=point[i];
            vertex[k].node2=point[j];
            vertex[k].cost=sqrt( (point[i].x-point[j].x)*(point[i].x-point[j].x) \
                                 +(point[i].y-point[j].y)*(point[i].y-point[j].y) );
            k++;
        }
    }
    sort(vertex,vertex+n*(n-1)/2);
    for(int i=0; i<n; i++)
    {
        printf("%.1lf %.1lf\n",point[i].x,point[i].y);
    }
    for(int i=0; i<k; i++)
    {
        printf("第%d路径：%d <=> %d: %.2lf\n",i,vertex[i].num1,vertex[i].num2,vertex[i].cost);
    }
    int temp=n*(n-1)/2;
    double cost_sum=0;
    for(int i=0; i<temp; i++)
    {
        int a=findroot(vertex[i].num1);
        int b=findroot(vertex[i].num2);
        if(a!=b)
        {
            Tree[a]=b;
            cost_sum+=vertex[i].cost;
        }
    }
    printf("最短路径为：%.2lf",cost_sum);


    fclose(stdin);
    return 0;
}
