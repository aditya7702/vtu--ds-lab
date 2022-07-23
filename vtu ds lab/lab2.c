#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int slen(char*);
void replace(char*,char*,char*,char*);
int main()
{
    char a[40];
    printf("enter string\n");
    scanf("%s",a);
    char p[20];
    printf("enter pattern\n");
    scanf("%s",p);

    char r[20];
    printf("enter replacement string\n");
    scanf("%s",r);
    char f[40];
    replace(a,p,r,f);
    printf("output is %s",f);
    return 0;
}
int slen(char *s)

{
        int len=0;
        for(;s[len]!='\0';len++);
        return len;
}
void replace(char *a,char *p,char *r,char *f)
{
    int k=0,l,q=0,z;
    int t=slen(a);
    int m=slen(p);
    int g=slen(r);
    const int MAX=t-m+1;
    for(;k<=t;)
     {

        for(l=0;l<m;l++)

            if(p[l]!=a[k+l])
                break;

        if(l==m)
          {
            printf("substring found at %d\n",k);
            for(z=0;z<g;z++)
                f[q++]=r[z];
            k=k+m;


          }
          else
          f[q++]=a[k++];
    }
    f[q]='\0';
}



