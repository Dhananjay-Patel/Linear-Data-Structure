// LIFO (Last in first out)
//stack using linked list
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

///node struture
struct node
{
    int data;
    struct node *next;
};
// initial address value

struct node *STACK = NULL;
struct node *TOP = NULL;

//creating node
struct node *CreateNode()
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    return (n);
}
//add value to stack
void push()
{
    struct node *temp, *t;
    temp = CreateNode();
    if (temp != NULL)
    {
        printf("Enter a num:");
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (STACK == NULL)
        {
            STACK = temp;
        }
        else
        {
            t = STACK;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
        }
    }
}

//delete value from stack
void pop()
{

    struct node *temp, *t;
    t = STACK;
    if (STACK == NULL)
    {
        printf("Stack is empty");
        return;
    }
    else
    {

        while (t->next != NULL)
        {
            if (t->next->next == NULL)
            {
                printf("%d is poped", t->next->data);
                temp = t->next;
                t->next = t->next->next;
                free(temp);
                return;
            }
            t = t->next;
        }
    }
}

//print all stack value
void display()
{
    struct node *temp;
    if (STACK == NULL)
    {
        printf("Stack is underflow!!");
    }
    else
    {
        temp = STACK;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

//main menu
int menu()
{
    int choice;
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    return (choice);
}

//main function
void main()
{
    while (1)
    {
        switch (menu())
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Wrong input!!");
            break;
        }
    }
}
