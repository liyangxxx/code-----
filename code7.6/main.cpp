#include <stdio.h>
#define OFFSET 2000 //��Ϊ������������ڸ��������,����һ�ѱȵڶ�����,�����ڼ����������Ӧ�������±�ʱ���ϸ�ƫ��ֵ,ʹÿ���������Ӧ�Ϸ��������±�
int dp[101][4001]; //����״̬
int list[101]; //�����������
#define INF 0x7fffffff //����

int main ()
{
    int T;
    int cas = 0; //�����Case��,�Ա����
    scanf ("%d",&T); //����Ҫ�������������
    while (T -- != 0)   //T��ѭ��
    {
        int n;
        scanf ("%d",&n);
        bool HaveZero = false; //ͳ���Ƿ��������Ϊ0�ĸ���
        int cnt = 0; //������,��¼���ж��ٸ���������ĸ���
        for (int i = 1; i <= n; i ++) //����n����������
        {
            scanf ("%d",&list[++ cnt]);
            if (list[cnt] == 0)   //����ǰ�����������Ϊ0
            {
                cnt --; //ȥ���������
                HaveZero = true; //����¼��������Ϊ0�ĸ���
            }
        }
        n = cnt;
        for (int i = -2000; i <= 2000; i ++)
        {
            dp[0][i + OFFSET] = -INF;
        } //��ʼ��,����dp[0][i]Ϊ�����ע��Ҫ�����������OFFSET���ȡ�����
        dp[0][0 + OFFSET] = 0; //dp[0][0]Ϊ0
        for (int i = 1; i <= n; i ++) //����ÿ������
        {
            for (int j = -2000; j <= 2000; j ++) //����ÿ�ֿ��ܵ�������
            {
                int tmp1 = -INF,tmp2 = -INF; //�ֱ��¼��ǰ���ٷ��ڵ�һ�ѻ�ڶ���ʱת�Ƶ�������ֵ,���޷�ת����Ϊ-INF
                if (j + list[i] <= 2000 && dp[i - 1][j + list[i] + OFFSET] != -INF)   //��״̬�����ɷ��ڵ�һ��ת�ƶ���ʱ
                {
                    tmp1 = dp[i - 1][j + list[i] + OFFSET] + list[i]; //��¼ת��ֵ
                }
                if (j - list[i] >= -2000 && dp[i - 1][j - list[i] + OFFSET] != -INF)   //��״̬�����ɷ��ڵڶ���ת�ƶ���ʱ
                {
                    tmp2 = dp[i - 1][j - list[i] + OFFSET] + list[i]; //��¼��ת��ֵ
                }
                if (tmp1 < tmp2)
                {
                    tmp1 = tmp2;
                } //ȡ�����нϴ���Ǹ�,������tmp1
                if (tmp1 < dp[i - 1][j + OFFSET])   //��tmp1�뵱ǰ���ٲ������κζѼ�״̬������ı��ԭ״ֵ̬�Ƚϣ�ȡ�ϴ��ֵ������tmp1
                {
                    tmp1 = dp[i - 1][j + OFFSET];
                }
                dp[i][j + OFFSET] = tmp1; //��ǰֵ״̬����Ϊ����ת����Դת�Ƶõ�����ֵ�������Ǹ�
            }
        }
        printf("Case %d: ",++ cas);//����Ŀ���Ҫ�����
        if (dp[n][0 + OFFSET] == 0)   //dp[n][0]Ϊ0
        {
            puts( HaveZero == true ? "0" : "-1");//�����Ƿ��������Ϊ0�ĸ������0��-1
        }
        else printf("%d\n",dp[n][0 + OFFSET] / 2); //�������dp[n][0] / 2
    }
    return 0;
}
