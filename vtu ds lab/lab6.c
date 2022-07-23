#include<stdio.h>
#include<stdlib.h>
#define MAX 3
void insert(int*,int*,int*);
void del(int*,int*,int*);
void display(int*,int,int);
int main()
{
    int q[MAX];
    int r=-1,f=0;
    int cnt=0;
    int ch;


    while(1)
    {
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert(q,&r,&cnt);
                    break;
            case 2:del(q,&f,&cnt);
                    break;
            case 3:display(q,f,cnt);
                    break;
            default:exit(0);
        }
    }


}
void insert(int *q,int *r,int *cnt)
{
    int ele;
    if((*cnt)==MAX)
    {
        printf("circular queue overflow\n");
        return;
    }
    (*r)=((*r)+1)%MAX;
    printf("enter ele\n");
    scanf("%d",&ele);
    q[*r]=ele;
    (*cnt)++;
}
void del(int *q,int *f,int *cnt)
{

    if((*cnt)==0)
    {

        printf("circular queue empty\n");
        return;

    }
    printf("element deleted from queue is %d",q[*f]);
    *f=((*f)+1)%MAX;
    (*cnt)--;
}
void display(int *q,int f,int cnt)
{

    int i,j;
    if(cnt==0)
    {

        printf("circular queue empty\n");
        return;
    }
    for(i=f,j=0;j<cnt;j++)
    {
        printf("%d:%d",i,q[i]);
        i=(i+1)%MAX;


    }
}




