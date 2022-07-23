#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int cf,ex,ey,ez;
    struct node *link;

};
typedef struct node tm;
void i_f(tm*);
void eval(tm*);
void display(tm*);
void polyadd(tm*,tm*,tm*);
int main()
{
    int n,i,ch;
    tm p={.link=&p};
    tm p1={.link=&p1};
    tm p2={.link=&p2};
    tm p3={.link=&p3};
    for(;;)
    {
        printf("1.polynomial evaluation\n2.polynomial addition\n3.exit\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter size of polynomial\n");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)

                        i_f(&p);
                        display(&p);
                        eval(&p);
                        break;
            case 2:printf("enter size of polynomial\n");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                        i_f(&p1);
                    printf("enter size of polynomial\n");
                    for(i=0;i<n;i++)
                        i_f(&p2);
                     polyadd(&p1,&p2,&p3);
                     display(&p3);

             default:return 0;

        }
    }
}
void i_f(tm* h)
{
    tm *t;
    t=(tm*)malloc(sizeof(tm));
    printf("enter value of x,y,z:\n");
    scanf("%d%d%d%d",&(t->cf),&(t->ex),&(t->ey),&(t->ez));
    t->link=h->link;
    h->link=t;
}
void eval(tm *h)
{
    int x,y,z;
    double sum=0;
    printf("enter value of x,y,z\n");
    scanf("%d%d%d",&x,&y,&z);
    tm *t;
    for(t=h->link;t!=h;t=t->link)
        sum=sum+(t->cf)*pow(x,t->ex)*pow(y,t->ey)*pow(z,t->ez);
    printf("the evaluation result is %lf",sum);
}
void display(tm *h)
{
    if(h->link==h)
    {
        printf("linked list is empty\n");
            return;
    }
    tm *t;
    for(t=h->link;t!=h;t=t->link)
    {
        printf("%dx^%dy^%dz^%d+",(t->cf),(t->ex),(t->ey),(t->ez));
    }
    printf("0\n");
}
void polyadd(tm *h1,tm *h2,tm *h3)
{
    tm *t1,*t2,*t3;
    for(t1=h1->link;t1!=h1;h1=h1->link)
    {
        for(t2=h2->link;t2!=h2;t2=t2->link)
        {
            if(t2->cf!=-999 && (t1->ex==t2->ex && t1->ey==t2->ey && t1->ez==t2->ez))
            {
                t3=(tm*)malloc(sizeof(tm));
                *t3=*t2;
                t3->cf+=t1->cf;
                t2->cf=-999;
                t3->link=h3->link;
                h3->link=t3;
                break;


            }
        }
       if(t2==h2)
       {
            t3=(tm*)malloc(sizeof(tm));
            *t3=*t1;
            t3->link=h3->link;
            h3->link=t3;
       }
    }
    for(t2=h2->link;t2!=h2;t2=t2->link)
    {
        if(t2->cf!=-999)
        {
            t3=(tm*)malloc(sizeof(tm));

            *t3=*t2;
            t3->link=h3->link;
            h3->link=t3;
        }
    }
}







