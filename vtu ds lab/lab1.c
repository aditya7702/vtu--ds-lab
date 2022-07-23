#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[20],ch,n;
    printf("enter no of array elements\n");
    scanf("%d",&n);
    for(;;){
        printf("1.accept\n2.insert_at_pos\n3.delete_at_pos\n4.display\n5.exit\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:accept(a,&n);
                    break;
            case 2:insert(a,&n);
                    break;
            case 3:delete(a,&n);
                    break;
            case 4:display(a,n);
                    break;
            case 5:return 0;
        }
    }
}
void accept(int *a,int *n)
{
    int i;
    for(i=0;i<(*n);i++)
        scanf("%d",&a[i]);
    printf("\n");

}
void display(int *a,int n)
{
    int i;printf("contents of array are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void insert(int *a,int *n)
{
    int i,ele,pos;
    printf("enter position\n");
    scanf("%d",&pos);
    if(pos<=0||pos>(*n)+1)
    {
        printf("invalid position\n");
        return;
    }
    printf("enter element to be inserted\n");
    scanf("%d",&ele);

    for(i=(*n)-1;i>=(pos-1);i--)
    {
        a[i+1]=a[i];

    }
    a[pos-1]=ele;
    (*n)++;

}
void delete(int *a,int *n)
{
    int i,pos;
     printf("enter position\n");
    scanf("%d",&pos);
    if(pos<=0||pos>(*n)-1)
    {
         printf("invalid position\n");
         return;
    }
    for(i=pos-1;i<*n;i++)
    {
        a[i]=a[i+1];
    }
    (*n)--;



}
