/*
///  ��������㷨  ʹ�ú���������

#include <stdio.h>

int K, T, A, B, C;
int maze[52][52][52];  //·Ϊ0
bool mark[52][52][52]; //�Ѿ��߹��ļ�Ϊtrue

int solve (int x, int y, int z, int t)
{
    ///  ===============   ���²��֣���֧�ķ���ֵ   ===============     ////


    ///  ���²��֣�������Ч��ֵ ///
    if (x==A && y==B && z==C && t<=T)  //����������
    {  //���ڱ���Ϊ0���������Ϊ1�����ʾ�����Ƕ�ס�ģ�ֻ�÷���-1
        return t;  //����ʱ��
    }

    ///  ���²��֣��������ڵĴ���ֵ  ///
    else if ((t>T)||  \
             (mark[x][y][z]==true)||  \
             (maze[x][y][z]==1))//��ʱ/�߹�/������
    {
        return -1;
    }

    ///  ���²��֣�����������    ///
    else
    {
        mark[x][y][z]=true;    ///  ���

        int ans[6];
        int ans_final;
        ans[0] = solve(x+1,y,z,t+1);    /// ��֧1
        ans[1] = solve(x,y+1,z,t+1);    /// ��֧2
        ans[2] = solve(x,y,z+1,t+1);    /// ��֧3
        ans[3] = solve(x-1,y,z,t+1);    /// ��֧4
        ans[4] = solve(x,y-1,z,t+1);    /// ��֧5
        ans[5] = solve(x,y,z-1,t+1);    /// ��֧6

        //printf("%d %d %d %d: %d %d %d %d %d %d\n",x,y,z,t,ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]);

        ///  ===============   ���²��֣���εķ���ֵ���������Сֵ   ===============     ////
        if(ans[0]==-1 && ans[1]==-1 && ans[2]==-1 \
        && ans[3]==-1 && ans[4]==-1 && ans[5]==-1)
        {
            ans_final = -1;
        }
        else
        {
            int min_ans=0;
            for (int i=0; i<6; i++)
            {
                if (ans[i]!=-1)
                {
                    min_ans = i;
                    break;
                }
            }
            for (int i=min_ans; i<6; i++)
            {
                if (ans[i]!=-1 && ans[i]<ans[min_ans])
                {
                    min_ans = i;
                }
            }
            ans_final = ans[min_ans];
        }

        return ans_final;
    }
}

int main()
{
    freopen("C:\\Users\\LENOVO\\Desktop\\input.txt","r",stdin);
    while(scanf("%d",&K)!=EOF)
    {
        for (int num=0; num<K; num++)
        {
            scanf("%d %d %d %d",&A,&B,&C,&T);
            for (int i=0; i<=A+1; i++)       //��ʼ��
            {
                for (int j=0; j<=B+1; j++)
                {
                    for (int k=0; k<=C+1; k++)
                    {
                        maze[i][j][k]=1;     //��·Ϊ0����·Ϊ1
                        mark[i][j][k]=false;//û���߹���Ϊfalse
                    }
                }
            }
            for (int i=1; i<=A; i++)         //�����ͼ
            {
                for (int j=1; j<=B; j++)
                {
                    for (int k=1; k<=C; k++)
                    {
                        scanf("%d",&maze[i][j][k]);
                    }
                }
            }
            if(maze[1][1][1]==1 || maze[A][B][C]==1)  //�ų���Чֵ
            {
                int i=-1;
                printf("%d\n",i);
            }
            else
            {
                int flag=solve(1,1,1,0);  //��������Ϊ�����x\y\z����ǰ����ʱ��
                printf("%d\n",flag);//flag����ȡ-1,��������������ʾʱ��
            }
        }
    }
    fclose(stdin);
    return 0;
}

*/
