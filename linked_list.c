#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *START = NULL;

struct node *CreateNode()
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    return (n);
}

void insert() //insert at end
{
    struct node *temp, *t;
    temp = CreateNode();
    printf("Enter a num:");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (START == NULL)
    {
        START = temp;
    }
    else
    {
        t = START;
        while (t->link != NULL)
        {
            t = t->link;
        }
        t->link = temp;
    }
}

void delete () //delete at start
{
    struct node *r;
    if (START == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        r = START;
        START = START->link;
        free(r);
    }
}

void ViewList()
{
    struct node *t;
    if (START == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        t = START;
        while (t != NULL)
        {
            printf("%d\n", t->data);
            t = t->link;
        }
    }
}

int menu()
{
    int choice;
    printf("1. Insert \n2. Delete \n3. Print \n4.Exit");
    printf("\nEnter your choice:");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    while (1)
    {

        switch (menu())
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            ViewList();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong input!!");
            break;
        }
    }
    return 0;
}
