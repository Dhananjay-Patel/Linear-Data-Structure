//FIFO(First in First Out)

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
} * front, *rear;

void enQueue(int data)
{
    struct Queue *temp;
    temp = (struct Queue *)malloc(sizeof(struct Queue));
    if (temp == NULL)
    {
        printf("temperory variable is null!");
    }
    else
    {
        temp->data = data;
        temp->next = NULL;
        if (rear == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = rear->next;
        }
    }
}

int deQueue()
{
    struct Queue *temp;
    int data = 0;
    if (front == NULL)
    {
        printf("\nQueue is Empty!\n");
        return 0;
    }
    else
    {
        data = front->data;
        temp = front;

        front = front->next;
        free(temp);
    }
    return data;
}

void display()
{
    struct Queue *temp;
    temp = front;
    if (front == NULL)
    {
        printf("Queue is empty!");
        return;
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
int menu()
{
    int choice;
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    return (choice);
}

int main()
{
    int data;
    while (1)
    {
        switch (menu())
        {
        case 1:
            printf("Enter a num:");
            scanf("%d", &data);
            enQueue(data);
            break;
        case 2:
            data = deQueue();
            printf("%d is deleted from queue", data);
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

    return 0;
}