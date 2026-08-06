#include<stdio.h>
int a[10][10], visited[10], queue[10];
int front = -1, rear = -1;

void bfs(int v, int n)
{
    int i;

    for(i=1;i<=n;i++)
    {
        if(a[v][i] && !visited[i])
        {
            queue[++rear] = i;
        }
    }

    if(front <= rear)
    {
        visited[queue[front]] = 1;
        bfs(queue[front++], n);
    }
}

int main()
{
    int n,i,j,start;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d",&start);

    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal: %d ", start);

    bfs(start,n);

    for(i=0;i<=rear;i++)
        printf("%d ", queue[i]);

    return 0;
}