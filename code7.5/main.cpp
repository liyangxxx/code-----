#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 0x7fffffff //Ԥ��������intȡֵΪ����

int list[2001]; //����ÿ����Ʒ����
int dp[1001][2001]; //����ÿ��״̬

int main ()
{
    int n, k;
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        for (int i=1; i<=n; i++)
        {
            scanf ("%d",&list[i]);
        } //����

        sort(list+1, list+1+n); //ʹ������Ʒ����������������
        for (int i=1; i<=n; i++) //��ʼֵ
            dp[0][i]=0;

        for (int i=1; i<=k; i++) //�������ÿ��״̬
        {
            for (int j=2*i; j<=n; j++)
            {
                if (j>2*i) //��j>2*i�����,���������Ʒ���Բ����,��ǰj-1����Ʒ�㹻���i�ԣ�dp[i][j]������dp[i][j - 1]ת�ƶ�������ֵ�ȱ�����Ϊdp[i][j - 1]
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = INF; //��j == 2 * i,˵�����������Ʒ�������,����ǰj����Ʒ�䲻��i��,������״̬������dp[i][j - 1]ת�ƶ�����dp[i][j]������Ϊ������
                if (dp[i][j] > dp[i - 1][j - 2] + (list[j] - list[j - 1]) * (list[j] - list[j - 1])) //��dp[i][j]��dp[i-1][j-2]ת�ƶ���ʱ����ֵ����֮ǰȷ���������������dp[i][j - 1]ת�ƶ�����ֵʱ�����¸�״̬
                    dp[i][j] = dp[i - 1][j - 2] + (list[j] - list[j - 1]) * (list[j] - list[j - 1]); //����
            }
        }
        printf("%d\n",dp[k][n]); //���
    }
    return 0;
}
