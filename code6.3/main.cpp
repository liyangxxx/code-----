#include <stdio.h>
#include <queue>
using namespace std;

struct N   //状态结构体
{
    int a , b, c; //每个杯子中可乐的体积
    int t; //得到该体积组倾倒次数
};
queue<N> Q; //队列

bool mark[101][101][101]; //对体积组（x，y，z）进行标记，即只有第一次得到包含体积组（x，y，z）的状态为有效状态，其余的舍去
void AtoB(int &a, int sa, int &b, int sb)
//倾倒函数,由容积为sa的杯子倒往容积为sb的杯子,其中引用参数a和b,
//初始时为原始杯子中可乐的体积，当函数调用完毕后，为各自杯中可乐的新体积
{
    if (sb - b >= a)   //若a可以全部倒到b中
    {
        b += a;
        a = 0;
    }
    else   //否则
    {
        a -= sb - b;
        b = sb;
    }
}
int BFS(int s,int n,int m)
{
    while(Q.empty() == false)   //当队列非空时,重复循环
    {
        N now = Q.front(); //拿出队头状态
        Q.pop(); //弹出队头状态
        int a , b , c; //a.b.c临时保存三个杯子中可乐体积
        a = now.a;
        b = now.b;
        c = now.c; //读出该状态三个杯子中可乐体积
        AtoB(a,s,b,n); //由a倾倒向b
        if (mark[a][b][c] == false)   //若该体积组尚未出现
        {
            mark[a][b][c] = true; //标记该体积组
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1; //生成新的状态
            if (a == s / 2 && b == s / 2) return tmp.t;
            if (c == s / 2 && b == s / 2) return tmp.t;
            if (a == s / 2 && c == s / 2) return tmp.t; //若该状态已经为平分状态,则直接返回该状态的耗时
            Q.push(tmp); //否则放入队列
        }
        a = now.a;
        b = now.b;
        c = now.c; //重置a.b.c为未倾倒前的体积
        AtoB(b,n,a,s); //b倒向a
        if (mark[a][b][c] == false)
        {
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if (a == s / 2 && b == s / 2) return tmp.t;
            if (c == s / 2 && b == s / 2) return tmp.t;
            if (a == s / 2 && c == s / 2) return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(a,s,c,m); //a倒向c
        if (mark[a][b][c] == false)
        {
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if (a == s / 2 && b == s / 2) return tmp.t;
            if (c == s / 2 && b == s / 2) return tmp.t;
            if (a == s / 2 && c == s / 2) return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(c,m,a,s); //c倒向a
        if (mark[a][b][c] == false)
        {
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if (a == s / 2 && b == s / 2) return tmp.t;
            if (c == s / 2 && b == s / 2) return tmp.t;
            if (a == s / 2 && c == s / 2) return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(b,n,c,m); //b倒向c
        if (mark[a][b][c] == false)
        {
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if (a == s / 2 && b == s / 2) return tmp.t;
            if (c == s / 2 && b == s / 2) return tmp.t;
            if (a == s / 2 && c == s / 2) return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(c,m,b,n); //c倒向b
        if (mark[a][b][c] == false)
        {
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if (a == s / 2 && b == s / 2) return tmp.t;
            if (c == s / 2 && b == s / 2) return tmp.t;
            if (a == s / 2 && c == s / 2) return tmp.t;
            Q.push(tmp);
        }
    }
    return -1;
}
int main()
{
    int s,n,m;
    while (scanf("%d%d%d",&s,&n,&m) != EOF)
    {
        if (s == 0) break; //若s为0,则n.m为0则退出
        if (s % 2 == 1)   //若s为奇数则不可能平分,直接输出NO
        {
            puts("NO");
            continue;
        }
        for (int i = 0; i <= s; i ++)
        {
            for (int j = 0; j <= n; j ++)
            {
                for (int k = 0; k <= m; k ++)
                {
                    mark[i][j][k] = false;
                }
            }
        } //初始化状态
        N tmp;
        tmp.a = s;
        tmp.b = 0;
        tmp.c = 0;
        tmp.t = 0; //初始时状态
        while(Q.empty() == false) Q.pop(); //清空队列中状态
        Q.push(tmp); //将初始状态放入队列
        mark[s][0][0] = true; //标记初始状态
        int rec = BFS(s,n,m); //广度优先搜索
        if (rec == -1) //若为-1输出NO
            puts("NO");
        else printf("%d\n",rec);//否则输出答案
    }
    return 0;
}
