#include<stdio.h>

#define max 20

struct queue
{
    int a[max];
    int r,f;
} q = {.r = -1, .f = 0};

void enqueue(int x)
{
    if(q.r == max-1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q.r++;
        q.a[q.r] = x;
    }
}

int dequeue()
{
    int x;

    if(q.r < q.f)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        x = q.a[q.f];
        q.f++;
        return x;
    }
}

void display()
{
    int i;

    if(q.r < q.f)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements: ");

    for(i=q.f; i<=q.r; i++)
    {
        printf("%d ", q.a[i]);
    }

    printf("\n");
}

int main()
{
    int ch, c;

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
                int x;

                x = dequeue();

                if(x != -1)
                    printf("Deleted element is %d\n",x);

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