#include<stdio.h>
#include<stdlib.h>
#define MAX 3
#include<stdio.h>
#include<stdlib.h>
#define MAX 3
void push(int*,int*);
void pop(int*,int*);
void display(int*,int);
void pallin();
int main()
{
    int ch;
    int a[MAX];
    int top=-1;
    for(;;)
    {
        printf("1.push\n2.pop\n3.diaplay\n4.pallindrome\n5.exit\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push(a,&top);
                    break;
            case 2:pop(a,&top);
                    break;
            case 3:display(a,top);
                    break;

            case 4:pallin();
                    break;
            case 5:exit(0);

        }
    }

}




void pop(int *a,int *top)
{

    if((*top)==-1)
    {

        printf("stack empty\n");
            return;
    }
    printf("deleted element is %d",a[*top]);
    (*top)--;
}
void display(int *a,int top)
{

    if(top==-1)
    {

        printf("staack empty\n");
            return;
    }
    printf("contents of stack are:");
    int i;
    for(i=top;i>=0;i--)
        printf("%d",a[i]);
}



void push(int *a,int *top)
{
    if((*top)==MAX-1)
    {

        printf("insertion not possible\n");
            return;
    }
    int n;

    printf("enter the number\n");
    scanf("%d",&n);
    a[++(*top)]=n;



}

void pallin()
{
    char a[20];
    printf("enter a integer value\n");
    scanf("%s",a);
    int start=0,top=strlen(a)-1;
    for(;start<top;)
    {

        if (a[top--]!=a[start++])
        {

            printf("not a pallindrome number\n");
                return;
        }
        printf("pallindrome no");
    }






}
