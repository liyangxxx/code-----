#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 101
int Tree[N];

int findRoot(int x)   //���Ҵ����ϵ����ĸ����
{
    if (Tree[x] == -1) return x;
    else
    {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

struct Edge   //�߽ṹ��
{
    int a , b; //����������ı��
    int cost; //�ñߵ�Ȩֵ
    bool operator < (const Edge &A) const   //����С�ں�ʹ����԰��ձ�Ȩ��С��������
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
        } //����
        sort(edge + 1,edge + 1 + n * (n - 1) / 2); //���ձ�Ȩֵ�����������еı�

        for (int i = 1; i <= n; i ++)
            Tree[i] = -1; //��ʼʱ���еĽ�㶼���ڹ����ļ���

        int ans = 0; //��С�������ϱ�Ȩ�ĺ�,��ʼֵΪ0
        for (int i = 1; i <= n * (n - 1) / 2; i ++) //���ձ�Ȩֵ����˳��������еı�
        {
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b); //���Ҹñ���������ļ�����Ϣ
            if (a != b)   //���������ڲ�ͬ����,��ѡ�øñ�
            {
                Tree[a] = b; //�ϲ���������
                ans += edge[i].cost; //�ۼӸñ�Ȩֵ
            }
        }
        printf("%d\n",ans); //���
        for(int i=1; i<=n; i++)
        {
            printf("Tree[%d]: %d\n",i,Tree[i]);
        }
    }
    fclose(stdin);
    return 0;
}
