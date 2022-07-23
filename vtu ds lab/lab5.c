#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
double compute(char symbol,double op1,double op2)
{
    switch(symbol)
    {
        case '+':return op1+op2;
        case '-':return op1-op2;
        case '*':return op1*op2;
        case '/':return op1/op2;
        case '$':
        case '^':return pow(op1,op2);
    }
}
int main()
{
    char pf[20],symbol;
    double st[20],op1,op2;
    int top=-1,i;
    printf("enter valid postfix expression\n");
    scanf("%s",pf);
    for(i=0;pf[i]!='\0';i++)
    {
        if(isdigit(pf[i]))
            st[++top]=pf[i]-'0';
        else
        {
            op2=st[top--];
            op1=st[top--];
            st[++top]=compute(pf[i],op1,op2);
        }
    }
    printf("result is %lf\n",st[top--]);

}
