#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 5
#define TRUE 1
#define FALSE 0

struct stack
{
    int top;
    int items[STACKSIZE];
};
typedef struct stack STACK;

void push(STACK *);
void pop(STACK *);
void print(STACK *);
void peek(STACK *);
int empty(STACK *);
int full(STACK *);

int main()
{
    STACK S;
    S.top = -1;
    int choice=0;

    while(1) {
        printf("\n Menu\n");
        printf("1-PUSH\n");
        printf("2-POP\n");
        printf("3-PEEK\n");
        printf("4-PRINT\n");
        printf("5-EXIT\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: push(&S);
                    break;
            case 2: pop(&S);
                    break;
            case 3: peek(&S);
                    break;
            case 4: print(&S);
                    break;
            case 5: printf("Terminating\n");
                    exit(1);
        }
    }

    return 0;
}

int full(STACK *S)
{
    if(S->top == STACKSIZE-1)
        return TRUE;
    else
        return FALSE;
}

void push(STACK *S)
{
    if(full(S)){
        printf("Stack full\n");
        return;
    }

    int x;
    printf("Enter the item to be pushed\n");
    scanf("%d", &x);

    S->top++;
    S->items[S->top] = x;

}

int empty(STACK * S)
{
   if(S->top == -1)
        return TRUE;
   else
        return FALSE;
}
void pop(STACK *S)
{
    if(empty(S)){
        printf("Stack Empty\n");
        return;
    }

    int x;
    x = S->items[S->top];
    printf("Popped item is %d\n", x);
    S->top--;
}

void peek(STACK *S)
{
    if(empty(S)){
        printf("Stack Empty\n");
        return;
    }

    int x;
    x = S->items[S->top];
    printf("Peeked item is %d\n", x);
}

void print(STACK *S)
{
    if(empty(S)){
        printf("Stack Empty\n");
        return;
    }

    int i;
    for(i = S->top; i >= 0; i--)
        printf("| %d |\n", S->items[i]);
}
