#include <stdio.h>

int main ()
{
    int buf[200];
    int n;
    while (scanf ("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i ++)
        {
            scanf ("%d",&buf[i]);
        } //输入数据
        int x , ans = -1; //初始化答案为-1，以期在找不到答案时能正确的输出-1
        scanf ("%d",&x);
        for (int i=0; i<n; i++)
        { //依次遍历数组元素
            if (x==buf[i])
            { //目标数字与数组元素依次比较
                ans = i;
                break; //找到答案后跳出循环
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
