#include<stdio.h>

int M;
void printGraph(int adj[][M])
{
    for(int i = 0; i<M; i++)
    {
        for(int j = 0; j<M; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int s,d;
    printf("\n Enter the number of Nodes : ");
    scanf("%d", &M);
    int adj[M][M];

    for(int i = 0; i<M; i++)
        for(int j = 0; j<M; j++)
            adj[i][j] = 0;

    while(s!=-1 && d!=-1)
    {
        printf("Enter an Edge fromnode(0 to %d) to node (0 to %d) : ", M,M);
        scanf("%d%d", &s,&d);
        s--;
        d--;
        adj[s][d]=1;
    }
    printGraph(adj);
    return 0;
}
