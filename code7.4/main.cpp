#include <stdio.h>
#include <string.h>
int dp[101][101];
int max(int a,int b)
{
    return a > b ? a : b;    //ȡ���ֵ����
}

int main ()
{
    char S1[101],S2[101];
    while (scanf ("%s%s",S1,S2) != EOF)   //����
    {
        int L1 = strlen(S1);
        int L2 = strlen(S2); //������������ַ����ĳ���

        for (int i = 0; i <= L1; i ++)
            dp[i][0] = 0;
        for (int j = 0; j <= L2; j ++)
            dp[0][j] = 0; //��ʼֵ

        for (int i = 1; i <= L1; i ++)
        {
            for (int j = 1; j <= L2; j ++) //����ѭ���������ÿ��dp[i][j]ֵ
            {
                if (S1[i - 1] != S2[j - 1]) //��Ϊ�ַ��������±��0��ʼ�����Ե�i���ַ�λ��ΪS1[i-1],����ǰ�����ַ������
                    dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]); //dp[i][j]Ϊdp[i][j - 1] �� dp[i - 1][j]�нϴ��һ��
                else dp[i][j] = dp[i - 1][j - 1] + 1; //��������ȣ���dp[i][j]��dp[i - 1][j - 1]�ټ�һ
            }
        }
        printf("%d\n",dp[L1][L2]); //�����
    }
    return 0;
}
