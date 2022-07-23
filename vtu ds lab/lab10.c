#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node nd;
nd* insert(nd*,int);
void search(nd*,int);
void preorder(nd*);
void inorder(nd*);
void postorder(nd*);


int main()
{
    nd *root=0;
    int ch,i,key;
    FILE *fp;
    fp=fopen("d.txt","r");
    for(;;)
    {
        printf("1.insert\n2.search\n3.preorder\n4.inorder\n5.postorder\n6.exit\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:fscanf(fp,"%d",&ch);
                    for(i=0;i<ch;i++)
                    {
                        fscanf(fp,"%d",&key);
                        root=insert(root,key);
                    }
                    break;
             case 2:printf("enter information to be searchred\n");
                    scanf("%d",&key);
                    search(root,key);
                    break;
             case 3:preorder(root);
                    break;
             case 4:inorder(root);
                    break;
            case 5:postorder(root);
                    break;
             case 6:return 0;
        }
    }
}
nd* insert(nd *root,int key)
{
    nd *cur=root,*prev=0;
    nd *t=(nd*)malloc(sizeof(nd));
    t->info=key;
    t->llink=t->rlink=0;
    if(!cur)
        return;
    while(cur)
    {
        if(t->info==cur->info)
        {
            printf("redundancy\n");
            free(t);
            return root;

        }
        prev=cur;
        if(t->info<cur->info)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }
    if(t->info<prev->info)
    {
        prev->llink=t;
    }
    else
        prev->rlink=t;
     return root;

}
void search(nd *root,int key)
{
    if(!root)
    {
        printf("bst empty\n");
        return;
    }
    while(root)
    {
        if(key==root->info)
        {
            printf("search successful\n");
            return;
        }
        if(key<root->info)
        {
            root=root->llink;

        }
        else
            root=root->rlink;

    }
    printf("unsuccessful search\n");
}
void preorder(nd *r)
{
    if(r)
    {
        printf("%d\n",r->info);
        preorder(r->llink);
        preorder(r->rlink);


    }
}
void inorder(nd *r)
{
    if(r)
    {
        inorder(r->llink);
        printf("%d\n",r->info);
        inorder(r->rlink);
    }
}
void postorder(nd *r)
{
    if(r)
    {
        postorder(r->llink);
        postorder(r->rlink);
        printf("%d\n",r->info);

    }
}
