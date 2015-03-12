#include <stdio.h>
#include <queue>
using namespace std;

bool mark[50][50][50]; //标记数组
int maze[50][50][50]; //保存立方体信息
struct N   //状态结构体
{
    int x , y , z;
    int t;
};
queue<N> Q; //队列,队列中的元素为状态
int go[][3] =   //坐标变换数组,由坐标(x,y,z)扩展得到的新坐标均可通过(x+go[i][0],y+go[i][1],z+go[i][2])得到
{
    1,0,0,
    -1,0,0,
    0,1,0,
    0,-1,0,
    0,0,1,
    0,0,-1
};
int BFS(int a,int b,int c)   //广度优先搜索,返回其最少耗时
{
    while(Q.empty() == false)   //当队列中仍有元素可以扩展时循环
    {
        N now = Q.front(); //得到队头状态
        Q.pop(); //从队列中弹出队头状态
        for (int i=0; i<6; i++) //依次扩展其六个相邻节点
        {
            int nx = now.x + go[i][0];
            int ny = now.y + go[i][1];
            int nz = now.z + go[i][2]; //计算新坐标
            if (nx<0 || nx>=a || ny<0 || ny>=b || nz<0 || nz>=c) continue; //若新坐标在立方体外,则丢弃该坐标
            if (maze[nx][ny][nz] == 1) continue; //若该位置为墙,则丢弃该坐标
            if (mark[nx][ny][nz] == true) continue; //若包含该坐标的状态已经被得到过,则丢弃该状态
            N tmp; //新的状态
            tmp.x = nx;
            tmp.y = ny;
            tmp.z = nz; //新状态包含的坐标
            tmp.t = now.t + 1; //新状态的耗时
            Q.push(tmp); //将该状态放入队列
            mark[nx][ny][nz] = true; //标记该坐标
            if (nx==a-1 && ny==b-1 && nz==c-1) return tmp.t; //若该坐标即为终点,可直接返回其耗时
        }
    }
    return -1; //若所有的状态被查找完后,仍得不到所需坐标,则返回-1
}
int main ()
{
    freopen("C:\\Users\\LENOVO\\Desktop\\input.txt","r",stdin);
    int K;
    while(scanf ("%d",&K)!=EOF)
    {
        while (K --)
        {
            int a , b, c , t;
            scanf ("%d%d%d%d",&a,&b,&c,&t); //输入
            for (int i=0; i<a; i++)
            {
                for (int j=0; j<b; j++)
                {
                    for (int k=0; k<c; k++)
                    {
                        scanf("%d",&maze[i][j][k]); //输入立方体信息
                        mark[i][j][k] = false; //初始化标记数组
                    }
                }
            }
            while(Q.empty() == false) Q.pop(); //清空队列
            mark[0][0][0] = true; //标记起点
            N tmp;
            tmp.t = tmp.y = tmp.x = tmp.z = 0; //初始状态
            Q.push(tmp); //将初始状态放入队列
            int rec = BFS(a,b,c); //广度优先搜索
            if (rec <= t) printf("%d\n",rec); //若所需时间符合条件,则输出
            else printf("-1\n"); //否则输出-1
        }
    }
    fclose(stdin);
    return 0;
}

