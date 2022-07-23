#include<stdio.h>
#include<stdlib.h>
struct student
{
    char usn[20];
    char nm[20];
    char phn[20];
    char branch[20];
    char sem[20];
};
typedef struct student st;
struct node
{
     st data;
    struct node *link;

};

typedef struct node nd;
int cnt=0;
nd* i_f(nd*);
nd* d_f(nd*);
nd* i_r(nd*);
nd* d_r(nd*);
int main()
{
    nd *f=0;
    for(;;)
    {
        int ch;
        printf("1.insert front\n2.delete front\n3.insert rear\n4.delete rear\n5.display\n6.stack simulation\n7.queue simulation\n8.exit\n");
        int n;
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
             case 5:display(f);
                    break;
             case 6:printf("1.push\n2.pop\n");
                        scanf("%d",&n);
                        if(n==1)
                        {
                            f=i_f(f);

                        }
                        else
                        {
                            f=d_f(f);
                        }
                        break;
            case 7:printf("1.insert\n2.delete\n");
                    scanf("%d",&n);
                    if(n==1)
                        f=i_r(f);
                    else
                        f=d_f(f);
                    break;
            default:exit(0);

        }

    }
}
nd* i_f(nd *f)
{
    cnt++;
    nd *t;
    t=(nd*)malloc(sizeof(nd));
    printf("enter details\n");
    scanf("%s%s%s%s%s",(t->data).usn,(t->data).nm,(t->data).phn,(t->data).branch,(t->data).sem);

    t->link=f;
    return t;


}
nd* d_f(nd *f)
{
    nd *t;
    if(f==0)
    {
        printf("linked list empty\n");

        return;
    }
    cnt--;
    if((f->link)==0)
    {
        printf("deleted element is %s%s%s%s%s",(f->data).usn,(f->data).nm,(f->data).phn,(f->data).branch,(f->data).sem);
        return 0;
    }

    printf("deleted element is %s%s%s%s%s",(f->data).usn,(f->data).nm,(f->data).phn,(f->data).branch,(f->data).sem);

    t=f->link;
    free(f);
    return t;

}
nd* i_r(nd *f)
{
    nd *t,*p;cnt++;
    t=(nd*)malloc(sizeof(nd));
    t->link=0;
    printf("enter details\n");
    scanf("%s%s%s%s%s",(t->data).usn,(t->data).nm,(t->data).phn,(t->data).branch,(t->data).sem);
    if(f==0)
    {
        return t;
    }

    for(p=f;p->link!=0;p=p->link);
        p->link=t;
        return f;




}
nd* d_r(nd *f)
{
    if(f==0){
        printf("empty\n");
        return f;
    }
     cnt--;
    if((f->link)==0)
    {
        printf("deleted element is%s%s%s%s%s",(f->data).usn,(f->data).nm,(f->data).phn,(f->data).branch,(f->data).sem);
        return 0;
    }
    nd *p,*w;

    for(p=f,w=0;p->link!=0;w=p,p=p->link);
    printf("deleted element is %s%s%s%s%s",(p->data).usn,(p->data).nm,(p->data).phn,(p->data).branch,(p->data).sem);
    w->link=0;
    return f;
 }
 void display(nd *f)
 {
    if(f==0)
    {
        printf("linked list empty\n");
        return f;

    }
    nd *t;
    for(t=f;t!=0;t=t->link)
    {
        printf("%s%s%s%s%s",(t->data).usn,(t->data).nm,(t->data).phn,(t->data).branch,(t->data).sem);

    }
 }

