#include <stdio.h>
long long F[21]; //��ֵ�ϴ�ѡ��long long
int main ()
{
    F[1] = 0;
    F[2] = 1; //��ʼֵ
    for (int i = 3; i <= 20; i ++)
        F[i] = (i - 1) * F[i - 1] + (i - 1) * F[i - 2]; //�����������ÿһ������
    int n;
    while (scanf ("%d",&n) != EOF)
    {
        printf("%lld\n",F[n]); //���
    }
    return 0;
}
