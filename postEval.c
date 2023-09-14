#include <stdio.h>
#define MAX 20

char stack[MAX], postfix[MAX];
int top=-1;

void push( char c){
    if(top==MAX-1){
        printf(“Stack full\n”);
        return;
        }
    else
        top++;
        stack[top]=c;
}

char pop(){
    char c;
    if(top==-1){
        printf("underflow ");
        exit(1);
    }
    c=stack[top];
    top=top-1;
    return c;
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
    printf("Enter postfix:\n");
    scanf("%s",postfix);

    int i=0;

    while(postfix[i]!='\0')
    {
        if(isOperand(postfix[i]) == 0)
        {
            push(postfix[i] - 48);
        }
        else
        {
            int res = 0;
            int b = pop();
            int a = pop();

            switch(postfix[i])
            {
                case '+':
                    res = a+b;
                    break;
                case '-':
                    res = a-b;
                    break;
                case '*':
                    res = a*b;
                    break;
                case '/':
                    res = a/b;
                    break;
                case '%':
                    res = a%b;
                    break;
                default : res = 0;
            }

            push(res);

        }
        i++;
    }

    printf("Answer = %d",pop());

    return 0;
}
        
        