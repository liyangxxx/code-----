#include <stdio.h>
long long F[91];//F���鱣�����е�ÿһ��ֵ��������ֵ����������Ҫʹ��long long����
int main ()
{
    F[1] = 1;
    F[2] = 2; //���г�ʼֵ
    for (int i = 3; i <= 90; i ++)
        F[i] = F[i - 1] + F[i - 2]; //����������е�ÿһ������
    int n;
    while (scanf ("%d",&n) != EOF)   //����
    {
        printf("%lld\n",F[n]); //�����Ӧ����������
    }
    return 0;
}
