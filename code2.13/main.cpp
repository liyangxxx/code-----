#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

typedef struct Student
{
    char no[100];
    char name[100];
    int age;
    char sex[5];
    bool operator < (const Student &A) const
    {
        return (strcmp(no,A.no)<0);
    }
}Student;

Student buf[1000];
char buf_char[10000][100];


int charSearchNo(char* buf_char, Student* buf, int n)
{
    int low=0;
    int high=n-1;

    while ( high!=low )
    {
        int mid = (low+high)/2;
        int flag = strcmp(buf[mid].no, buf_char);
        if(flag==0) return mid;
        else if(flag>0) high=mid-1;
        else low=mid+1;
    }
    int flag = strcmp(buf[high].no, buf_char);
    if(flag==0) return high;
    else return -1;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)  //scan the number of students <=1000
    {
        for(int i=0; i<n; i++)  //scan n students' information
        {
            scanf("%s %s %s %d",buf[i].no,\
                                buf[i].name,\
                                buf[i].sex,\
                                &buf[i].age);
        }
        sort(buf,buf+n);

        int m;
        scanf("%d",&m);//scan the number of querys

        for(int i=0; i<m; i++)  //scan the querys
        {
            scanf("%s",buf_char[i]);
        }

        for(int i=0; i<m; i++)
        {
            int j = charSearchNo(buf_char[i],buf,n);
            if(j==-1) printf("No Answer!\n");
            else printf("%s %s %s %d\n",buf[j].no,\
                                      buf[j].name,\
                                      buf[j].sex,\
                                      buf[j].age);
        }
    }

    return 0;
}
