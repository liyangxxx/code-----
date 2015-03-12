#include <stdio.h>

int max(int a,int b)
{
    return a > b ? a : b;    //ȡ���ֵ����
}

int list[26]; //��Ϯ���¼�˳�򱣴�������߶�
int dp[26]; //dp[i]�����Ե�i��������β������������г���

int main()
{
    int n;
    while (scanf ("%d",&n) != EOF)
    {
        for (int i = 1; i <= n; i ++)
        {
            scanf ("%d",&list[i]);
        } //����
        for (int i = 1; i <= n; i ++) //����Ϯ��ʱ��˳��ȷ��ÿһ��dp[i]
        {
            int tmax = 1; //���ֵ�ĳ�ʼֵΪ1���������β������������г�������Ϊ1
            for (int j = 1; j < i; j ++) //������ǰ���е����߶�
            {
                if (list[j] >= list[i])   //��j�ŵ������ȵ�ǰ������
                {
                    tmax = max(tmax,dp[j] + 1); //����ǰ������������j�ŵ�����β�������������֮�󣬼����䳤��dp[j] + 1,�����ڵ�ǰ���ֵ����������ֵ
                }
            }
            dp[i] = tmax; //��dp[i]����Ϊ���ֵ
        }
        int ans = 1;
        for (int i = 1; i <= n; i ++)
        {
            ans = max(ans,dp[i]);
        } //�ҵ���ÿһ��Ԫ�ؽ�β��������������е����ֵ,�����ֵ��Ϊ��
        printf("%d\n",ans); //���
    }
    return 0;
}


/*
if(n>0)
for(int i=1; i<n; i++)
{
    b[i]=1;
    for(int j=0; j<i; j++)
    {
        if(a[i]>=a[j] && b[j]+1>b[i])
            b[i]=b[j]+1;
    }
}
*/
