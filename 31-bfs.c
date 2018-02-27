

#include <stdio.h>
#include <stdlib.h>

/*
Funtion Name: bfs
Input Params: Graph input as matrix, number of vertices and source vertex
Return Type:  void
Description:  performs bfs traversal on the given graph
*/
void bfs(int m[10][10], int v, int source)
{
    /// A queue will be used during the traversal
    int queue[20];
    int front = 0;
    int rear = 0;

    /// Temporary variables
    int u;
    int i;

    /// Array to maintain the visited vertices
    int visited[10];

    /// Set all the vertices to not visited
    for (i= 0; i < v; i ++)
        visited[i] = 0;

    /// Initilaize the queue with source and mark it visited
    queue[rear] = source;
    visited[source] = 1;

    printf("The BFS Traversal is... \n");

    /// Until the queue is empty
    while (front <= rear)
    {
        /// Pick the vertex from queue front
        /// This is also when we mark the traversal and print it
        u = queue[front];
        printf("%d\t", u);
        front = front + 1;

        /// All the vertices that are reachable from considered vertex
        /// and not yet visited,
        /// Mark them as visited and Add them to queue
        for(i=0;i<v;i++)
        {
            if(m[u][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                rear = rear + 1;
                queue[rear] = i;
            }
        }
    }
}

int main()
{
    /// Variable to hold the number of vertices
    int v = 5;

    /// Variable to hold the graph as matrix
    int m[10][10] =
                    {
                        {0, 1, 1, 0, 0},
                        {1, 0, 0, 1, 1},
                        {1, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0},
                        {0, 1, 1, 0, 0}
                    };

    /// Variable to hold source vertex
    int source = 4;

    /// Call the bfs traversal
    bfs(m, v, source);

    return 0;
}
