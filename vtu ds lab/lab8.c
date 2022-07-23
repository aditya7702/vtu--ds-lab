#include<stdio.h>
#include<stdlib.h>
struct employee
{
    char ssn[20];
    char nm[40];
    char dept[20];
    char sal[20];
    char dn[20];
    char ph[10];
};
typedef struct employee emp;
struct node
{
    struct node *llink;
    emp d;
    struct node *rlink;
};
typedef struct node nd;
nd* i_f(nd*);
nd* d_f(nd*);
nd* i_r(nd*);
nd* d_r(nd*);
void display(nd*);
int main()
{
    nd *f=0;
    int ch,n;
    for(;;)
    {
        printf("1.insert front\n2.delete front \n3.inser rear\n4.delete rear\n5.double ended queue\n6.display\n7.exit\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:f=i_f(f);
                    break;
             case 2:f=d_f(f);
                    break;
             case 3:f=i_r(f);
                    break;
              case 4:f=d_r(f);
                    break;
              case 5:printf("1.insert front\n2.delete front\n3.insert rear\n4.delete rear\n");
                     printf("enter choice\n");
                     scanf("%d",&n);
                    switch(n)
                    {
                        case 1:f=i_f(f);
                               break;
                        case 2:f=d_f(f);
                               break;
                        case 3:f=i_r(f);
                               break;
                        case 4:f=d_r(f);
                               break;
                        default:return 0;


                    }
                    break;
              case 6:display(f);
                        break;

              default:exit(0);
        }
    }

}
nd* i_f(nd *f)
{
    nd *t;
    t=(nd*)malloc(sizeof(nd));
    printf("enter details\n");
    scanf("%s%s%s%s%s%s",(t->d).ssn,(t->d).nm,(t->d).dept,(t->d).dn,(t->d).sal,(t->d).ph);
    if(f==0)
    {
        t->llink=t->rlink=0;
        return t;
    }
    t->rlink=f;
    t->llink=0;
    f->llink=t;

    return t;

}
nd* d_f(nd *f)
{
    nd *t;
    if(f==0)
    {
        printf("doubly linked list is empty\n");
        return 0;

    }

    if(f->rlink==0)
    {
        printf("deleted element is %s    %s   %s  %s   %s    %s\n",(f->d).ssn,(f->d).nm,(f->d).dept,(f->d).dn,(f->d).sal,(f->d).ph);
        free(f);
        return 0;
    }
    t=f;
     printf("%s %s %s %s %s %s\n",(t->d).ssn,(t->d).nm,(t->d).dept,(t->d).dn,(t->d).sal,(t->d).ph);
    (t->rlink)->llink=0;
    f=t->rlink;
    free(t);
    return f;


}
nd* i_r(nd *f)
{
    nd *t=(nd*)malloc(sizeof(nd));
    printf("enter details\n");
    scanf("%s%s%s%s%s%s",(t->d).ssn,(t->d).nm,(t->d).dept,(t->d).dn,(t->d).sal,(t->d).ph);
    t->rlink=0;

    if(f==0)
    {
        t->llink=0;
        return t;
    }
    nd *p;
    for(p=f;p->rlink!=0;p=p->rlink);
        p->rlink=t;
        t->llink=p;
        return f;
}
nd* d_r(nd *f)
{
    nd *t;
    if(f==0)
    {
        printf("doubly linked list is empty\n");
        return f;
    }
    if(f->rlink==0)
    {
        printf("deleted detail is %s    %s   %s  %s   %s    %s",(f->d).ssn,(f->d).nm,(f->d).dept,(f->d).dn,(f->d).sal,(f->d).ph);
        free(f);
        return 0;
    }
    nd *p;
    for(t=f;t->rlink!=0;p=t,t=t->rlink);
     printf("%s %s %s %s %s %s",(t->d).ssn,(t->d).nm,(t->d).dept,(t->d).dn,(t->d).sal,(t->d).ph);

        p->rlink=0;
        free(t);
        return f;


}
void display(nd *f)
{
    nd *t;
    if(f==0)
    {
        printf("doubly linked list is empty\n");
        return;
    }

    printf("contents of doubly linked list are:\n");
    for(t=f;t!=0;t=t->rlink)
    {


        printf("%s %s %s %s %s %s",(t->d).ssn,(t->d).nm,(t->d).dept,(t->d).dn,(t->d).sal,(t->d).ph);
        printf("\n");



    }
}

