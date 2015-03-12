#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    char string[101]={'\0'};//初始化

    while (scanf("%s",string)!=EOF)
    {
        stack<int> stack_Temp;
        char string_target[101]={'\0'};//初始化

        for(int string_Pos=0; string[string_Pos]!='\0'; string_Pos++)
        {
            if (string[string_Pos]=='(')  //左括号的标号入栈
            {
                stack_Temp.push(string_Pos);
            }
            else if (string[string_Pos]==')')
            {
                if (stack_Temp.size()!=0)//如果匹配则改为空格
                {
                    int i=stack_Temp.top();
                    stack_Temp.pop();
                    string_target[i]=' ';
                    string_target[string_Pos]=' ';
                }
                else //不匹配的右括号改为?
                {
                    string_target[string_Pos]='?';
                }
            }
            else //字符改为空格
            {
                string_target[string_Pos]=' ';
            }
        }
        while (stack_Temp.size()!=0)
        {
            int i=stack_Temp.top();
            stack_Temp.pop();
            string_target[i]='$';
        }

        cout<<string<<endl;
        cout<<string_target<<endl;
    }
    return 0;
}
