#include<stdio.h>
#include<stdlib.h>
#define max 5

int front=-1,rear=-1,que[max];
void insert();
void delete();
void display();

int main()
{
    int choice;
    while(1)
    {
        printf("\nPerform operations on the queue:");
        printf("\n1.insert the element\n2.delete the element\n3.display all element\n4.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
         case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);

        default:
            printf("\nInvalid choice!!");
        }
    }
    return 0;
}

void insert()
{
    int num;

    if((front==0 && rear==max-1)||(front==rear+1))
    {
        printf("overflow!");
        return;
    }
    printf("enter number to be inserted in queue:-");
    scanf("%d",&num);
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear==max-1)
    {
        rear=0;
    }
    else
    {
        rear=rear+1;
    }
    que[rear]=num;
    printf("%d is added into quere\n",num);
}

void delete()
{
    if (front == -1)
    {
        printf("underflow!\n");
        return;
    }
    int val=que[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==max-1)
    {
        front=0;
    }
    else{
        front=front+1;
    }
    printf("%d has been deleted from queue\n",val);
}

void display()
{
    int i;
    if(front==-1)
    {
        printf("underflow!");
        return;
    }
    else if(front<=rear)
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d ",que[i]);
        }
    }
    else
    {
        for(i=front;i<max;i++)
        {
            printf("%d ",que[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%d ",que[i]);
        }
    }
    printf("\n");
}