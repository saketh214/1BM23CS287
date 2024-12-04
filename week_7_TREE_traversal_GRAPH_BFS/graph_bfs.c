#include <stdio.h>

void BFS(int adj[10][10], int n, int source){
    int que[10];
    int front =0; 
    int rear=-1;
    int visited[10]={0};

    printf("The Nodes visited from %d: ", source);
    que[++rear] = source;
    visited[source] = 1;
    printf("%d",source);
    while(front<=rear){
        int u = que[front++];
        for(int v=0; v<n; v++){
            if(adj[u][v]==1){
                if(visited[v]==0){
                    printf("%d",v);
                    visited[v]=1;
                    que[++rear]=v;
                }
            }
        }
    }
    printf("\n");

}

int main(){
    int adj[10][10];
    int n;
    printf("Enter Number of nodes \n");
    scanf("%d",&n);
    printf("Enter Adjacency Matrix: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&adj[i][j]);
        }
    }

    for(int source=0; source<n; source++){
        BFS(adj,n,source);
    }
}
