/*
///  深度优先算法  使用函数迭代法

#include <stdio.h>

int K, T, A, B, C;
int maze[52][52][52];  //路为0
bool mark[52][52][52]; //已经走过的记为true

int solve (int x, int y, int z, int t)
{
    ///  ===============   以下部分：分支的返回值   ===============     ////


    ///  以下部分：返回有效的值 ///
    if (x==A && y==B && z==C && t<=T)  //结束的条件
    {  //出口必须为0，如果出口为1，则表示出口是堵住的，只好返回-1
        return t;  //返回时间
    }

    ///  以下部分：返回碰壁的错误值  ///
    else if ((t>T)||  \
             (mark[x][y][z]==true)||  \
             (maze[x][y][z]==1))//超时/走过/不能走
    {
        return -1;
    }

    ///  以下部分：迭代处理部分    ///
    else
    {
        mark[x][y][z]=true;    ///  标记

        int ans[6];
        int ans_final;
        ans[0] = solve(x+1,y,z,t+1);    /// 分支1
        ans[1] = solve(x,y+1,z,t+1);    /// 分支2
        ans[2] = solve(x,y,z+1,t+1);    /// 分支3
        ans[3] = solve(x-1,y,z,t+1);    /// 分支4
        ans[4] = solve(x,y-1,z,t+1);    /// 分支5
        ans[5] = solve(x,y,z-1,t+1);    /// 分支6

        //printf("%d %d %d %d: %d %d %d %d %d %d\n",x,y,z,t,ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]);

        ///  ===============   以下部分：层次的返回值：本层次最小值   ===============     ////
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
            for (int i=0; i<=A+1; i++)       //初始化
            {
                for (int j=0; j<=B+1; j++)
                {
                    for (int k=0; k<=C+1; k++)
                    {
                        maze[i][j][k]=1;     //有路为0；无路为1
                        mark[i][j][k]=false;//没有走过的为false
                    }
                }
            }
            for (int i=1; i<=A; i++)         //输入地图
            {
                for (int j=1; j<=B; j++)
                {
                    for (int k=1; k<=C; k++)
                    {
                        scanf("%d",&maze[i][j][k]);
                    }
                }
            }
            if(maze[1][1][1]==1 || maze[A][B][C]==1)  //排除无效值
            {
                int i=-1;
                printf("%d\n",i);
            }
            else
            {
                int flag=solve(1,1,1,0);  //参数依次为：起点x\y\z，当前已用时间
                printf("%d\n",flag);//flag可以取-1,或者正整数，表示时间
            }
        }
    }
    fclose(stdin);
    return 0;
}

*/
