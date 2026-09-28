#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int stk[SIZE];
int sp = -1;

void push(int);
int pop(void);
void print(void);

int main(void)
{
    int opt, item;

    do
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                printf("Enter your item: ");
                scanf("%d", &item);

                push(item);
                break;

            case 2:
                item = pop();

                if (item != -9)
                {
                    printf("Popped value = %d\n", item);
                }
                break;

            case 3:
                print();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    while (1);

    return 0;
}


void push(int item)
{
    if (sp == SIZE - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        sp++;
        stk[sp] = item;

        printf("%d pushed into stack.\n", item);
    }
}


int pop(void)
{
    int item;

    if (sp == -1)
    {
        printf("Stack Underflow!\n");
        return -9;
    }
    else
    {
        item = stk[sp];
        sp--;

        return item;
    }
}


void print(void)
{
    int i;

    if (sp == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements are:\n");

        for (i = sp; i >= 0; i--)
        {
            printf("%d\n", stk[i]);
        }
    }
}
