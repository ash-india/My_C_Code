#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *c;
};
typedef struct stack st;

int isempty(st *ss)
{
    if(ss->top == -1)
        return 1;
    else
        return 0;
}

int isoperator(char op)
{
    
    if(op=='+' || op=='-' || op=='*' || op=='/')
        return 1;
    else
        return 0;
}

void push(st *ss, char x)
{
    ss->c[++ss->top] = x;
}

char pop(st *ss)
{
    char x = ss->c[ss->top--];
    return x;
}

char peek(st *ss)
{
    char x = ss->c[ss->top];
    return x;
}

int priority(char x)
{
    if(x=='*' || x=='/')
        return 2;
    else if(x=='+' || x=='-')
        return 1;
    return 0;
}

void infix_to_postfix(st *ss, char e[])
{
    int i=0;
    char x;
    while(e[i]!='\0')
    {
        if(isalnum(e[i]))
            printf("%c",e[i]);
        else if(e[i] == '(')
            push(ss,e[i]);
        else if(e[i] == ')')
        {
            while((x = pop(ss)) != '(')
                printf("%c",x);
        }
        else if(isoperator(e[i]))
        {
            while((ss->top > -1) && (priority(peek(ss)) >= priority(e[i])))
                printf("%c",pop(ss));
            push(ss,e[i]);
        }
        i++;
    }
    while(!isempty(ss))
    {
        printf("%c",pop(ss));
    }
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
    int n;
    n = input(exp,100);
    st s1;
    s1.size=n;
    s1.top=-1;
    s1.c=(char *)malloc(sizeof(char)*n);
    infix_to_postfix(&s1,exp);
}