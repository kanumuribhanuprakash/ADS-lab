#include<stdio.h>

#define max 20

struct stack
{
    int a[max];
    int top;
} s;    

void insert(int x)
{
    if(s.top == max-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s.top++;
        s.a[s.top] = x;
    }
}

int delete()
{
    int x;

    if(s.top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        x = s.a[s.top];
        s.top--;
        return x;
    }
}

void peak()
{
    if(s.top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top Element = %d\n", s.a[s.top]);
    }
}

void display()
{
    int i;

    if(s.top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    for(i = s.top; i >= 0; i--)
    {
        printf("%d ", s.a[i]);
    }

    printf("\n");
}

int main()
{
    int ch, c;
    s.top=-1;

    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Peak\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            {
                int x;

                printf("Enter element: ");
                scanf("%d", &x);

                insert(x);
                display();
                break;
            }

            case 2:
            {
                int x;

                x = delete();

                if(x != -1)
                    printf("Deleted Element = %d\n", x);

                display();
                break;
            }

            case 3:
            {
                display();
                break;
            }

            case 4:
            {
                peak();
                break;
            }

            default:
            {
                printf("Invalid Choice\n");
            }
        }

        printf("Continue (1/0): ");
        scanf("%d", &c);

    } while(c);

    return 0;
}