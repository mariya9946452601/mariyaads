#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *push(struct node *, int);
struct node *pop(struct node *, int *);
void display(struct node *);
int search(struct node *, int);

int main(void)
{
    struct node *sp = NULL;
    int opt, data, found;

    do
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);

                sp = push(sp, data);
                break;

            case 2:
                if (sp == NULL)
                {
                    printf("Stack is empty!\n");
                }
                else
                {
                    sp = pop(sp, &data);
                    printf("Popped element is: %d\n", data);
                }
                break;

            case 3:
                display(sp);
                break;

            case 4:
                printf("Enter the element to be searched: ");
                scanf("%d", &data);

                found = search(sp, data);

                if (found != 0)
                    printf("The element %d is present.\n", data);
                else
                    printf("%d not found.\n", data);
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }

    } while (1);

    return 0;
}

/* Push operation */
struct node *push(struct node *sp, int data)
{
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return sp;
    }

    temp->data = data;
    temp->next = sp;
    sp = temp;

    return sp;
}

/* Pop operation */
struct node *pop(struct node *sp, int *x)
{
    struct node *temp;

    if (sp != NULL)
    {
        temp = sp;
        *x = sp->data;
        sp = sp->next;
        free(temp);
    }

    return sp;
}
void display(struct node *sp)
{
    if (sp == NULL)
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements are:\n");

    while (sp != NULL)
    {
        printf("%d\n", sp->data);
        sp = sp->next;
    }
}

/* Search operation */
int search(struct node *sp, int data)
{
    while (sp != NULL)
    {
        if (sp->data == data)
            return 1;

        sp = sp->next;
    }

    return 0;
}

