#include<stdio.h>
#include<string.h>
#define SIZE 100

char stack[SIZE][SIZE];
int top = -1;

void push(char c[SIZE])
{
    if(top >= SIZE )
    {
        printf("Stack out of bound");
        return;
    }

    strcpy(stack[++top],c);

}

char* pop()
{
    if(top < 0)
    {
        printf("Stack empty");
        return "9999999999";
    }
    return (stack[top--]);
}

int isOperand(char c)
{
    switch(c)
    {
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%': return 1;
        default : return 0;
    }
}

int main()
{
    char postfix[SIZE];
    printf("Enter postfix:\n");
    scanf("%s",postfix);

    int i=0;
    while(postfix[i]!='\0')
    {
        char curPost = postfix[i];
        if(isOperand(curPost) == 0)
        {
            char temp[3];
            temp[0] = curPost;
            temp[1] = '\0';
            push(temp);


        }
        else
        {
            char temp[SIZE];
            int a,b;
            b = pop();
            a = pop();
            strcpy(temp,"(");
            strcat(temp,a);
            char temp1[3];
            temp1[0] = curPost;
            temp1[1] = '\0';
            strcat(temp,temp1);
            strcat(temp,b);
            strcat(temp,")");
            push(temp);
        }
        i++;
    }

    printf("Infix = %s", stack);

    return 0;
}
