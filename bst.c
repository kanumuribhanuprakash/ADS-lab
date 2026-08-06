#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

struct node *insert(struct node *root,int x)
{
    struct node *temp;

    if(root==NULL)
    {
        temp=(struct node *)malloc(sizeof(struct node));

        temp->data=x;
        temp->left=NULL;
        temp->right=NULL;

        return temp;
    }

    if(x < root->data)
    {
        root->left=insert(root->left,x);
    }
    else if(x > root->data)
    {
        root->right=insert(root->right,x);
    }
    else
    {
        printf("Duplicate element not allowed\n");
    }

    return root;
}
void del(int x)
{
    int c=0;

    struct node *p=root,*p1=NULL,*q,*parent;

    while(p!=NULL)
    {
        if(p->data==x)
        {
            c=1;
            break;
        }

        p1=p;

        if(x < p->data)
            p=p->left;
        else
            p=p->right;
    }

    if(c==0)
    {
        printf("Element not found\n");
        return;
    }

    /* Case 1 : Leaf Node */

    if(p->left==NULL && p->right==NULL)
    {
        if(p==root)
            root=NULL;
        else if(p1->left==p)
            p1->left=NULL;
        else
            p1->right=NULL;

        printf("Deleted node is %d\n",p->data);
        free(p);
    }

    /* Case 2 : Only Left Child */

    else if(p->left!=NULL && p->right==NULL)
    {
        if(p==root)
            root=p->left;
        else if(p1->left==p)
            p1->left=p->left;
        else
            p1->right=p->left;

        printf("Deleted node is %d\n",p->data);
        free(p);
    }

    /* Case 3 : Only Right Child */

    else if(p->left==NULL && p->right!=NULL)
    {
        if(p==root)
            root=p->right;
        else if(p1->left==p)
            p1->left=p->right;
        else
            p1->right=p->right;

        printf("Deleted node is %d\n",p->data);
        free(p);
    }

    /* Case 4 : Two Children */

    else
    {
        parent=p;
        q=p->right;

        while(q->left!=NULL)
        {
            parent=q;
            q=q->left;
        }

        p->data=q->data;

        if(parent->left==q)
            parent->left=q->right;
        else
            parent->right=q->right;

        free(q);
    }
}


void inorder(struct node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}
void preorder(struct node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(struct node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
  
    }
}

int main()
{
    int ch,c,x;

    do
    {
        printf("\n1.Insert\n2.Inorder\n3.preorder\n4.postorder\n5.deletion\n");
        printf("Enter Choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            {
                printf("Enter element: ");
                scanf("%d",&x);

                root=insert(root,x);

                break;
            }

            case 2:
            {
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            }
            case 3:
            {
                printf("preorder: ");
                preorder(root);
                printf("\n");
                break;
            }
            case 4:
            {
                printf("postorder: ");
                postorder(root);
                printf("\n");
                break;
            }
            case 5:
            {
                printf("enter element:");
                scanf("%d",&x);
                del(x);
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