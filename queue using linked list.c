#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *r=NULL,*f=NULL,*temp;

void enqueue(int x)
{
    temp=(struct node*)malloc(sizeof(struct node));

    temp->data=x;
    temp->next=NULL;

    if(f==NULL && r==NULL)
    {
        f=r=temp;
    }
    else
    {
        r->next=temp;
        r=temp;
    }
}

void dequeue()
{
    if(f==NULL && r==NULL)
    {
        printf("Queue Underflow\n");
    }
    else if(f==r)
    {
        printf("Deleted element is %d\n",f->data);

        free(f);

        f=NULL;
        r=NULL;
    }
    else
    {
        temp=f;
        f=f->next;

        printf("Deleted element is %d\n",temp->data);

        free(temp);
    }
}

void display()
{
    temp=f;

    if(f==NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements: ");

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

    printf("\n");
}

int main()
{
    int ch,c;

    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            {
                int x;

                printf("Enter element: ");
                scanf("%d",&x);

                enqueue(x);
                display();
                break;
            }

            case 2:
            {
                dequeue();
                display();
                break;
            }

            case 3:
            {
                display();
                break;
            }

            default:
            {
                printf("Invalid Choice\n");
            }
        }

        printf("Continue (1/0): ");
        scanf("%d",&c);

    }while(c);

    return 0;
}