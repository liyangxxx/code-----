#include <stack>
#include <stdio.h>
using namespace std;
char str[220]; //�������ʽ�ַ���
int mat[5][5] =   //���ȼ�����,��mat[i][j] == 1�����ʾi����������ȼ�����j���������������������Ϊ+Ϊ1�ţ�-Ϊ2�ţ�*Ϊ3�ţ�/Ϊ4��,������Ϊ�����ڱ���ʽ��β�ı�������Ϊ0��
{
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,1,1,0,0},
    {1,1,1,0,0},
};

stack<int> op; //�����ջ,������������
stack<double> in; //����ջ,���������ܴ��ڸ�����,���Ա���Ԫ��Ϊdouble

void getOp(bool &reto,int &retn,int &i)   //��ñ���ʽ����һ��Ԫ�غ���,���������н���ʱ,���ñ���retoΪtrue,���ʾ��Ԫ��Ϊһ�������,���ű��������ñ���retn�У����򣬱�ʾ��Ԫ��Ϊһ�����֣���ֵ���������ñ���retn��.���ñ���i��ʾ���������ַ����±�
{
    if (i == 0 && op.empty() == true)   //����ʱ�����ַ�����һ���ַ�,�������ջΪ��,������Ϊ���ӱ��Ϊ0�ı���ַ�
    {
        reto = true; //Ϊ�����
        retn = 0; //���Ϊ0
        return; //����
    }
    if (str[i] == 0)   //����ʱ�����ַ�Ϊ���ַ�,���ʾ�ַ����Ѿ���������
    {
        reto = true; //����Ϊ�����
        retn = 0; //���Ϊ0�ı���ַ�
        return; //����
    }
    if (str[i] >= '0' && str[i] <= '9')   //����ǰ�ַ�Ϊ����
    {
        reto = false; //����Ϊ����
    }
    else   //����
    {
        reto = true; //����Ϊ�����
        if (str[i] == '+')   //�Ӻŷ���1
        {
            retn = 1;
        }
        else if (str[i] == '-')   //���ŷ���2
        {
            retn = 2;
        }
        else if (str[i] == '*')   //�˺ŷ���3
        {
            retn = 3;
        }
        else if (str[i] == '/')   //���ŷ���4
        {
            retn = 4;
        }
        i += 2;//i����,�����������ַ��͸������ַ���Ŀո�
        return; //����
    }
    retn = 0; //���ؽ��Ϊ����
    for (; str[i] != ' ' && str[i] != 0; i ++) //���ַ���δ��������,����һ���ַ����ǿո�,�����α����������,���㵱ǰ���������ַ���ʾ����ֵ
    {
        retn *= 10;
        retn += str[i] - '0';
    } //��������ֵ�����ֵ
    if (str[i] == ' ') //������ַ�Ϊ�ո�,���ʾ�ַ���δ��������
        i ++; //i����.�����ÿո�
    return;//����
}
int main()
{
    while(gets(str))   //�����ַ���,����λ���ļ�βʱ,gets����0
    {
        if (str[0] == '0' && str[1] == 0) break; //������ֻ��һ��0,���˳�
        bool retop;
        int retnum; //���庯����������ñ���
        int idx = 0; //������������ַ����±�,��ʼֵΪ0
        while(!op.empty()) op.pop();
        while(!in.empty()) in.pop(); //�������ջ,�������ջ
        while(true)   //ѭ����������ʽ�ַ���
        {
            getOp(retop,retnum,idx); //��ȡ����ʽ����һ��Ԫ��
            if (retop == false)   //����Ԫ��Ϊ����
            {
                in.push((double)retnum); //����ѹ������ջ��
            }
            else   //����
            {
                double tmp;
                if (op.empty() == true || mat[retnum][op.top()] == 1)
                {
                    op.push(retnum);
                }//���������ջΪ�ջ��ߵ�ǰ����������������ȼ�����ջ�������,���������ѹ���������ջ
                else   //����
                {
                    while(mat[retnum][op.top()] == 0)   //ֻҪ��ǰ��������ȼ�С��ջ��Ԫ�������,���ظ�ѭ��
                    {
                        int ret = op.top(); //����ջ�������
                        op.pop(); //����
                        double b = in.top();
                        in.pop();
                        double a = in.top();
                        in.pop(); //�����ֶ�ջջ��������������,���α����ڱ���a.b��
                        if (ret == 1) tmp = a + b;
                        else if (ret == 2) tmp = a - b;
                        else if (ret == 3) tmp = a * b;
                        else tmp = a / b; //��������������������
                        in.push(tmp); //�����ѹ�����ֶ�ջ
                    }
                    op.push(retnum); //����ǰ�����ѹ���������ջ
                }
            }
            if (op.size() == 2 && op.top() == 0) break; //���������ջֻ������Ԫ��,����ջ��Ԫ��Ϊ��������,���ʾ����ʽ��ֵ����
        }
        printf("%.2f\n",in.top()); //�������ջ��Ψһ������,��Ϊ��
    }
    return 0;
}