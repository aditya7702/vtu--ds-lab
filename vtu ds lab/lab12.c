#include<stdio.h>
#include<stdlib.h>
#define hz 3
FILE *fp;
struct employee
{
    int eno;
    char nm[20];
    int sal;
};
typedef struct employee emp;
struct hashtable
{
    int key;
    long int addr;
};
typedef struct hashtable ht;
int hashval(int);
void insert(ht*,int);
void search(ht*,int);
void display(ht*,int);
int main()
{
    ht h[hz];

    int ch,i,n;
    fp=fopen("em.txt","w+");
    for(n=0;n<hz;n++)
        h[n].key=-1;
    for(;;)
    {
        printf("1.insert\n2.search\n3.display\n4.exit\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter no of employees\n");
                    scanf("%d",&n);
                    insert(h,n);
                    break;
            case 2:search(h,n);
                    break;
             case 3:display(h,n);
                    break;
             default:exit(0);
        }
    }
}
int hashval(int num)
{
    int key;
    key=num%hz;
    return key;
}
void search(ht *h,int n)
{
    emp a;
    int cindex,hindex;
    printf("enter emp no to be search\n");
    scanf("%d",&(a.eno));
    hindex=hashval(a.eno);
    cindex=hindex;
    while(h[hindex].key!=a.eno)
    {
        hindex=(hindex+1)%hz;
        if(cindex==hindex)
        {
            printf("unsuccessful search");
            return;
        }
    }
    printf("successful search\n");
    fseek(fp,h[hindex].addr,SEEK_SET);
    fscanf(fp,"%d%s%d",&(a.eno),a.nm,&(a.sal));
    printf("%d  %s  %d",a.eno,a.nm,a.sal);
}


void display(ht *h,int n)
{
	emp a;
	int i,j;
	for(i=0;i<hz;i++)
	{
		if(h[i].key!=-1)
		{
			printf("Hash table:%d %ld\t",h[i].key,h[i].addr);
			fseek(fp,h[i].addr,SEEK_SET);
			fscanf(fp,"%d%s%d",&(a.eno),a.nm,&(a.sal));
			printf("contents are: %d   %s   %d\n",(a.eno),a.nm,(a.sal));

		}
	}
}
void insert(ht *h,int n)
{
    emp a;
    int flag=0;
    int i,cindex,hindex;
    for(i=0;i<n;flag=0,i++)
    {
        printf("enter empno name and sal\n");
        scanf("%d%s%d",&(a.eno),a.nm,&(a.sal));
        hindex=hashval(a.eno);
        cindex=hindex;
        while(h[hindex].key!=-1)
        {
            hindex=(hindex+1)%hz;
            flag=1;
            if(hindex==cindex)
            {
                printf("entry not possible\n");
                return;
            }
        }
            h[hindex].key=a.eno;
            h[hindex].addr=ftell(fp);
            fprintf(fp,"%d %s %d\n",a.eno,a.nm,a.sal);
            printf("entry successful\n");
            if(flag)
            printf("linear probing used\n");


    }
}
