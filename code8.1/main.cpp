#include <stdio.h>
#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
    char str[101];
    gets(str); //������ַ���
    string a = str; //���䱣����a��
    for (int i=0; i<a.size(); i++)
    {
        a[i]=tolower(a[i]);
    } //��a�е��ַ�ȫ���ĳ�Сд
    while (gets(str))   //���볤�ַ���
    {
        string b=str, c=b; //���ַ���������b,c
        for (int i=0; i<b.size(); i++)
        {
            b[i]=tolower(b[i]);
        } //��b���ַ�ȫ���ĳ�Сд,�Ա�ƥ��
        int t=b.find(a,0); //��b�в���a��λ��
        while (t!=string::npos)   //�����ҳɹ�,���ظ�ѭ��
        {
            c.erase(t,a.size()); //ɾ��c����Ӧλ���ַ�,cΪԭ��
            b.erase(t,a.size()); //ɾ��b����Ӧλ���ַ�,bΪ��ΪСд�ַ��Ĵ�
            t=b.find(a,t); //��������b����һ�������ַ���a��λ��
        }
        t=c.find(' ',0); //����c�пո�
        while(t!=string::npos)
        {
            c.erase(t,1);
            t = c.find(' ',0);
        } //ɾ��c�����пո�
        cout << c << endl; //���
    }
    return 0;
}
