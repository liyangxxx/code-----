#include <stdio.h>

int main ()
{
    int buf[200];
    int n;
    while (scanf ("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i ++)
        {
            scanf ("%d",&buf[i]);
        } //��������
        int x , ans = -1; //��ʼ����Ϊ-1���������Ҳ�����ʱ����ȷ�����-1
        scanf ("%d",&x);
        for (int i=0; i<n; i++)
        { //���α�������Ԫ��
            if (x==buf[i])
            { //Ŀ������������Ԫ�����αȽ�
                ans = i;
                break; //�ҵ��𰸺�����ѭ��
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
