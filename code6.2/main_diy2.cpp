/*
//��������㷨

#include <stdio.h>
#include <queue>

using namespace std;

struct c_footstep
{
    int x,y,z,t;
};

int K,A,B,C,T;    //ȫ�ֱ���
bool mark[52][52][52];
int maze[52][52][52];
queue<c_footstep> queue_Footstep;   //queue of footsteps
int go[6][3]=
{
    {1,0,0},
    {-1,0,0},
    {0,1,0},
    {0,-1,0},
    {0,0,1},
    {0,0,-1}
};

int BFS(c_footstep footstep)
{
    while(queue_Footstep.empty()==false)      /// ���в�����һֱȡ
    {
        c_footstep cur_footstep = queue_Footstep.front();//ȡ��ǰ״̬
        queue_Footstep.pop();   //��������
        int cur_x = cur_footstep.x;   //��״̬
        int cur_y = cur_footstep.y;
        int cur_z = cur_footstep.z;
        int cur_t = cur_footstep.t;

        for(int i=0; i<6; i++)
        {
            int next_x = cur_x+go[i][0];
            int next_y = cur_y+go[i][1];
            int next_z = cur_z+go[i][2];
            int next_t = cur_t+1;

            //printf("%d %d %d %d��    ",next_x,next_y,next_z,next_t);

            /// ����ĳ��״̬��˵������ֻ�����������һ���������ɹ���һ���ǳ�ʱ��һ���ǿ��Խ�����һ������һ�㣩����
            if(next_x==A && next_y==B && next_z==C && next_t<=T)  /// ������յ�Ļ�
            {
                //printf("%d",next_t);
                return next_t;
            }
            else if(next_t>T)                /// �����ʱ�Ļ�
            {
                //printf("-1 ��ʱ");
                return -1;
            }
            else if(maze[next_x][next_y][next_z]==0 \
                 && mark[next_x][next_y][next_z]==false )     /// ��������ߵĻ�
            {
                mark[next_x][next_y][next_z]=true; /// һ��Ҫ���ñ�ǣ�����һ��
                footstep.x = next_x;
                footstep.y = next_y;
                footstep.z = next_z;
                footstep.t = next_t;
                queue_Footstep.push(footstep);    ///  ��ǰ״̬�������
            }
        }
    }
    //printf("-1 ���п�");
    ///�����ѭ���ڲ�û����ɣ���һ������Ͷ��·���˳���
    return -1;
}

int main()
{
    freopen("C:\\Users\\LENOVO\\Desktop\\input.txt","r",stdin);
    c_footstep footstep;
    while(scanf("%d",&K)!=EOF)//��ȡ��Ŀ
    //scanf("%d",&K);
    {
        printf("%d\n",K);
        for(int num=0; num<K; num++)
        {
            //printf("%d",(int)queue_Footstep.empty());
            while(queue_Footstep.empty()==false)//�ǿն���
            {
                queue_Footstep.pop();
            }
            //printf("%d",(int)queue_Footstep.empty());
            scanf("%d %d %d %d",&A,&B,&C,&T);
            printf("%d %d %d %d\n",A,B,C,T);
            for(int i=0; i<52; i++)   //initialization
            {
                for(int j=0; j<52; j++)
                {
                    for(int k=0; k<52; k++)
                    {
                        maze[i][j][k]=1;
                        mark[i][j][k]=false;
                    }
                }
            }
            for(int i=1; i<=A; i++)    //given value
            {
                for(int j=1; j<=B; j++)
                {
                    for(int k=1; k<=C; k++)
                    {
                        scanf("%d",&maze[i][j][k]);
                        printf("%d ",maze[i][j][k]);
                    }
                    printf("\n");
                }
            }

            if(maze[1][1][1]==1 || maze[A][B][C]==1)//������ڻ���ڲ�ͨ
            {
                int i=-1;
                printf("%d:  ��ڻ���ڲ�ͨ",i);
            }
            else
            {
                footstep.x=footstep.y=footstep.z=1;
                footstep.t=0;
                queue_Footstep.push(footstep);
                int flag=BFS(footstep);
                printf("%d\n",flag);
            }
        }
    }

    fclose(stdin);
    return 0;
}
*/
