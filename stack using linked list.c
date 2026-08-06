#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top=NULL,*temp,*t;

void push(int x)
{
    temp=(struct node*)malloc(sizeof(struct node));

    temp->data=x;
    temp->next=NULL;

    if(top==NULL)
    {
        top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        t=top;
        top=t->next;
        printf("Deleted element is %d\n",t->data);
        free(t);
    }
}

void display()
{
    t=top;

    if(top==NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack Elements: ");

    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }

    printf("\n");
}

int main()
{
    int ch,c;

    do
    {
        printf("\n1.Push\n2.Pop\n3.Display\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            {
                int x;

                printf("Enter element: ");
                scanf("%d",&x);

                push(x);
                display();
                break;
            }

            case 2:
            {
                pop();
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