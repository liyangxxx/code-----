#include <stdio.h>
#include <stack>
using namespace std;

char shizi_ch[200];
stack<double> temp_num;
stack<char> temp_manipulator;
char* temp_num_push(char* shizi_char);
char* temp_cheng(char* shizi_char);
char* temp_chu(char* shizi_char);

int main()
{
    while(scanf("%s",shizi_ch)!=EOF)
    {
        char *shizi_char=shizi_ch;  //指针初始化，指向第一个字符
        //printf("%s\n",shizi_char);

        while (*shizi_char!='\0')
        {
            switch (*shizi_char)
            {
            case '+':
                temp_manipulator.push('+');
                shizi_char++;
                break;
            case '-':
                temp_manipulator.push('-');
                shizi_char++;
                break;
            case '*':
                shizi_char=temp_cheng(shizi_char);
                //shizi_char++;
                break;
            case '/':
                shizi_char=temp_chu(shizi_char);
                //shizi_char++;
                break;
            default:
                shizi_char = temp_num_push(shizi_char);
                //printf("%c 222\n",*(shizi_char-1));
            }
        }

        while(temp_manipulator.size()!=0)
        {
            if(temp_manipulator.top()=='+')
            {
                double int_a = temp_num.top();
                temp_num.pop();

                double int_b = temp_num.top();
                temp_num.pop();
                temp_num.push(int_b+int_a);
                printf("%lf + %lf = %lf\n",int_b,int_a,temp_num.top());
            }
            else if(temp_manipulator.top()=='-')
            {
                double int_a = temp_num.top();
                temp_num.pop();
                double int_b = temp_num.top();
                temp_num.pop();

                temp_num.push(int_b-int_a);
                printf("%lf - %lf = %lf\n",int_b,int_a,temp_num.top());
            }
            temp_manipulator.pop();
        }
        printf("结果是：%.3lf\n",temp_num.top());

        while(temp_num.size()!=0)
        {
            temp_num.pop();
        }
        while(temp_manipulator.size()!=0)
        {
            temp_num.pop();
        }
    }
    return 0;
}

char* temp_num_push(char* shizi_char)  //返回值为当前的算数串指针
{
    stack<double> temp_num_i; //shen qing yi ge lin shi zhan
    while(*shizi_char>='0' && *shizi_char<='9')     //入栈
    {
        double i=(double)((*shizi_char)-'0');
        temp_num_i.push(i);
        shizi_char++;
    }

    double temp_num_i_sum = 0;                       //计算数值
    int temp_ii = 1;
    while(temp_num_i.size()!=0)
    {
        temp_num_i_sum += (temp_num_i.top()*temp_ii);
        temp_num_i.pop();
        temp_ii *= 10;
    }
    temp_num.push(temp_num_i_sum);                //运算数字入栈

    return shizi_char;
}

char* temp_cheng(char* shizi_char)
{
    shizi_char++;
    stack<double> temp_num_i; //shen qing yi ge lin shi zhan
    while(*shizi_char>='0' && *shizi_char<='9')     //入栈
    {
        double i=(double)((*shizi_char)-'0');
        temp_num_i.push(i);
        shizi_char++;
    }

    double temp_num_i_sum = 0;                       //计算数值
    int temp_ii = 1;
    while(temp_num_i.size()!=0)
    {
        temp_num_i_sum += (temp_num_i.top()*temp_ii);
        temp_num_i.pop();
        temp_ii *= 10;
    }

    temp_num_i_sum *= temp_num.top();
    temp_num.pop();
    temp_num.push(temp_num_i_sum);

    return shizi_char;
}

char* temp_chu(char* shizi_char)
{
    shizi_char++;
    stack<double> temp_num_i; //shen qing yi ge lin shi zhan
    while(*shizi_char>='0' && *shizi_char<='9')     //入栈
    {
        double i=(double)((*shizi_char)-'0');
        temp_num_i.push(i);
        shizi_char++;
    }

    double temp_num_i_sum = 0;                       //计算数值
    int temp_ii = 1;
    while(temp_num_i.size()!=0)
    {
        temp_num_i_sum += (temp_num_i.top()*temp_ii);
        temp_num_i.pop();
        temp_ii *= 10;
    }

    temp_num_i_sum = temp_num.top()/temp_num_i_sum;
    temp_num.pop();
    temp_num.push(temp_num_i_sum);

    return shizi_char;
}
