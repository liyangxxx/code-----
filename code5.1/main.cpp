#include <stdio.h>
#define N 1000
int Tree[N];

int findRoot(int x)   //����ĳ������������ĸ����
{
    if (Tree[x] == -1) return x;
    else
    {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp; //·��ѹ�������Ǳ���ģ�
        return tmp;
    }
}

int main()
{
    freopen("C:\\Users\\LENOVO\\Desktop\\input.txt","r",stdin);
    int n , m;
    while (scanf("%d",&n)!=EOF && n!=0)
    {
        scanf ("%d",&m);
        for (int i=1; i<=n; i++) Tree[i]=-1;
        //��ʼʱ,���н�㶼�ǹ����ļ���,�������ڼ���ֻ��һ�����,�䱾����������������

        while(m-- != 0)   //�������Ϣ
        {
            int a, b;
            scanf ("%d %d",&a,&b);
            a = findRoot(a);
            b = findRoot(b); //���ұߵ������������ڼ�����Ϣ
            if (a!=b) Tree[a]=b; //���������㲻��ͬһ��������ϲ�����������
        }
        int ans=0;
        for (int i=1; i<=n; i++)
        {
            if (Tree[i]==-1) ans++; //ͳ�����н���и����ĸ���
        }
        printf("%d\n",ans-1); //�𰸼�Ϊ��ans�����ϼ����޽�ans-1����·����ʹ���н����ͨ
    }
    fclose(stdin);
    return 0;
}
