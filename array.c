#include<stdio.h>

int a[15], n, i;

void insert(int pos,int x)
{
    if(pos!=n)
    {
        for(i=n-1;i>=pos-1;i--)   // Changed <= to >=
        {
            a[i+1]=a[i];
        }
    }

    a[pos-1]=x;      // Moved outside loop
    n++;             // Increment only once
}

void del(int pos)
{
    if(pos!=n)
    {
        for(i=pos-1;i<n-1;i++)
        {
            a[i]=a[i+1];
        }
    }
    n--;
}

void search(int k)
{
    int found=0;

    for(i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            printf("%d element found at pos %d\n",k,i+1);
            found++;
        }
    }

    if(!found)
    {
        printf("Element not found\n");
    }
}

void display()
{
    for(i=0;i<n;i++)      // Changed o to 0
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int pos,ch,key;

    printf("Enter size of the array: ");
    scanf("%d",&n);       // Changed &a[i] to &n

    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    do
    {
        printf("\n1-Insertion\n2-Deletion\n3-Search\n4-Display\n5-Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            {
                int x;
                printf("Enter element: ");
                scanf("%d",&x);
                printf("Enter position: ");
                scanf("%d",&pos);
                insert(pos,x);
                display();
                break;
            }

            case 2:
            {
                printf("Enter position: ");
                scanf("%d",&pos);
                del(pos);
                display();
                break;      // Removed ()
            }

            case 3:
            {
                printf("Enter key: ");
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
                break;

            default:
                printf("Invalid Choice\n");
        }

    }while(ch!=5);

    return 0;
}