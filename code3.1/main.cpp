#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    char string[101]={'\0'};//��ʼ��

    while (scanf("%s",string)!=EOF)
    {
        stack<int> stack_Temp;
        char string_target[101]={'\0'};//��ʼ��

        for(int string_Pos=0; string[string_Pos]!='\0'; string_Pos++)
        {
            if (string[string_Pos]=='(')  //�����ŵı����ջ
            {
                stack_Temp.push(string_Pos);
            }
            else if (string[string_Pos]==')')
            {
                if (stack_Temp.size()!=0)//���ƥ�����Ϊ�ո�
                {
                    int i=stack_Temp.top();
                    stack_Temp.pop();
                    string_target[i]=' ';
                    string_target[string_Pos]=' ';
                }
                else //��ƥ��������Ÿ�Ϊ?
                {
                    string_target[string_Pos]='?';
                }
            }
            else //�ַ���Ϊ�ո�
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
