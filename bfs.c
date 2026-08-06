#include<stdio.h>

int stack[20], top = -1;
int visited[20];
int a[20][20], n;

void push(int v)
{
    stack[++top] = v;
}

int pop()
{
    return stack[top--];
}

void dfs(int start)
{
    int i, v;

    push(start);

    while(top != -1)
    {
        v = pop();

        if(visited[v] == 0)
        {
            printf("%d ", v);
            visited[v] = 1;
        }

        for(i=n;i>=1;i--)
        {
            if(a[v][i] == 1 && visited[i] == 0)
            {
                push(i);
            }
        }
    }
}

int main()
{
    int i,j,start;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d",&start);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}