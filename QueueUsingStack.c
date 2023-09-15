#include<stdio.h>
#define SIZE 100

int stack[SIZE*2];
int top[2] = {-1,SIZE-1};
int limit[2] = {99,199};

void insert(int val)
{
    push(0,val);
}

int delete()
{
    while(top[0] > -1)
    {
        push(1,pop(0));
    }
    int res = pop(1);
    while(top[1] > 99)
    {
        push(0,pop(1));
    }
    return res;
}


void push(int ind, int val)
{
    top[ind]++;
    if(top[ind] > limit[ind])
    {
        printf("Stack out of bound");
        return;
    }

    stack[top[ind]] = val;
}

int pop(int ind)
{
    if(top[ind] < -1 + (SIZE*ind))
    {
        printf("Stack empty\n");
        return -99999;
    }
    return (stack[top[ind]--]);
}

void disp()
{
    for(int i=0;i<=top[0];i++)
    {
        printf("%d  ", stack[i]);
    }
    printf("\n");
}

int main()
{
    //Sample input output
    insert(1);
    disp();
    insert(2);
    disp();
    insert(3);
    disp();
    insert(4);
    disp();
    delete();
    disp();
    delete();
    disp();
    insert(7);
    disp();

    return 0;
}
