#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL,*temp,*t;

void ins(int x,int pos)
{
    int i;

    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
    }
    else if(pos==1)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        t=head;

        for(i=1;i<pos-1 && t!=NULL;i++)
        {
            t=t->next;
        }

        if(t==NULL)
        {
            printf("Invalid Position\n");
            free(temp);
            return;
        }

        temp->next=t->next;
        t->next=temp;
    }
}

void del(int pos)
{
    int i;
    struct node *t1;

    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else if(pos==1)
    {
        t=head;
        head=t->next;
        printf("Deleted node is %d\n",t->data);
        free(t);
    }
    else
    {
        t=head;

        for(i=1;i<pos-1 && t!=NULL;i++)
        {
            t=t->next;
        }

        if(t==NULL || t->next==NULL)
        {
            printf("Invalid Position\n");
            return;
        }

        t1=t->next;
        t->next=t1->next;

        printf("Deleted node is %d\n",t1->data);

        free(t1);
    }
}

void display()
{
    if(head==NULL)
    {
        printf("List is Empty\n");
        return;
    }

    t=head;

    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }

    printf("\n");
}

void search(int key)
{
    int pos=1;

    t=head;

    while(t!=NULL)
    {
        if(t->data==key)
        {
            printf("%d found at position %d\n",key,pos);
            return;
        }

        t=t->next;
        pos++;
    }

    printf("Element not found\n");
}

int main()
{
    int ch,c;

    do
    {
        printf("\n1.Insertion\n2.Deletion\n3.Search\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            {
                int x,pos;

                printf("Enter the data: ");
                scanf("%d",&x);

                printf("Enter the position: ");
                scanf("%d",&pos);

                ins(x,pos);
                display();
                break;
            }

            case 2:
            {
                int pos;

                printf("Enter the position: ");
                scanf("%d",&pos);

                del(pos);
                display();
                break;
            }

            case 3:
            {
                int key;

                printf("Enter the key: ");
                scanf("%d",&key);

                search(key);
                break;
            }

            case 4:
            {
                display();
                break;
            }

            case 5:
            {
                printf("Program Ended\n");
                break;
            }

            default:
            {
                printf("Invalid Choice\n");
            }
        }

        if(ch==5)
            break;

        printf("Continue (1/0): ");
        scanf("%d",&c);

    }while(c);

    return 0;
}