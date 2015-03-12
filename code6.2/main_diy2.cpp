/*
//广度优先算法

#include <stdio.h>
#include <queue>

using namespace std;

struct c_footstep
{
    int x,y,z,t;
};

int K,A,B,C,T;    //全局变量
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
    while(queue_Footstep.empty()==false)      /// 队列不空则一直取
    {
        c_footstep cur_footstep = queue_Footstep.front();//取当前状态
        queue_Footstep.pop();   //弹出舍弃
        int cur_x = cur_footstep.x;   //读状态
        int cur_y = cur_footstep.y;
        int cur_z = cur_footstep.z;
        int cur_t = cur_footstep.t;

        for(int i=0; i<6; i++)
        {
            int next_x = cur_x+go[i][0];
            int next_y = cur_y+go[i][1];
            int next_z = cur_z+go[i][2];
            int next_t = cur_t+1;

            //printf("%d %d %d %d：    ",next_x,next_y,next_z,next_t);

            /// 对于某个状态来说，总是只有三种情况，一种是搜索成功，一种是超时，一种是可以进行下一步（下一层）搜索
            if(next_x==A && next_y==B && next_z==C && next_t<=T)  /// 如果是终点的话
            {
                //printf("%d",next_t);
                return next_t;
            }
            else if(next_t>T)                /// 如果超时的话
            {
                //printf("-1 超时");
                return -1;
            }
            else if(maze[next_x][next_y][next_z]==0 \
                 && mark[next_x][next_y][next_z]==false )     /// 如果可以走的话
            {
                mark[next_x][next_y][next_z]=true; /// 一定要做好标记：到此一游
                footstep.x = next_x;
                footstep.y = next_y;
                footstep.z = next_z;
                footstep.t = next_t;
                queue_Footstep.push(footstep);    ///  当前状态加入队列
            }
        }
    }
    //printf("-1 队列空");
    ///如果在循环内部没有完成，则一定是走投无路而退出了
    return -1;
}

int main()
{
    freopen("C:\\Users\\LENOVO\\Desktop\\input.txt","r",stdin);
    c_footstep footstep;
    while(scanf("%d",&K)!=EOF)//读取数目
    //scanf("%d",&K);
    {
        printf("%d\n",K);
        for(int num=0; num<K; num++)
        {
            //printf("%d",(int)queue_Footstep.empty());
            while(queue_Footstep.empty()==false)//非空队列
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

            if(maze[1][1][1]==1 || maze[A][B][C]==1)//表明入口或出口不通
            {
                int i=-1;
                printf("%d:  入口或出口不通",i);
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
