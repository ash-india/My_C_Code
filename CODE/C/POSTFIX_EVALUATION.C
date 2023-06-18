#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct stack{
    int size;
    int top;
    int *data;
};
typedef struct stack st;

int isoperator(char op)
{
    
    if(op=='+' || op=='-' || op=='*' || op=='/')
        return 1;
    else
        return 0;
}

void push(st *s1,int x)
{
    s1->data[++s1->top]=x;
}

int pop(st *s1)
{
    int x=s1->data[s1->top--];
    return x;
}

int eval_postfix(st *s1, char postfix[])
{
    int x1,x2,result,i=0;
    while(postfix[i] != '\0')
    {
        if(isalnum(postfix[i]))
            push(s1,postfix[i] - '0');
        else if(isoperator(postfix[i]))
        {
            x2=pop(s1);
            x1=pop(s1);
            switch(postfix[i])
            {
                case '+':result=x1+x2;break;
                case '-':result=x1-x2;break;
                case '*':result=x1*x2;break;
                case '/':result=x1/x2;break;
            }
            push(s1,result);
        }
        i++;
    }
    return pop(s1);
}

int input(char *e,int len)
{
    int ch,i = 0;
    while((ch = getchar()) != '\n')
    {
        if(i < len)
            e[i++]=ch;
    }
    e[i]='\0';
    return i;
}

int main()
{
    char exp[100];
    int len=input(exp,100);
    st s1;
    s1.size=len;
    s1.top=-1;
    s1.data=(int *)malloc(sizeof(int)*len);
    printf("Result is %d",eval_postfix(&s1,exp));
}