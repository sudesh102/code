#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjList;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node*)malloc(V * sizeof(struct Node));

    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}


void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;
}

void DFSUtil(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void DFS(struct Graph* graph, int source) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    DFSUtil(graph, source, visited);

    free(visited);
}

int main() {
    int V, edges, startVertex, endVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (startVertex endVertex):\n");
    for (int i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &startVertex, &endVertex);
        addEdge(graph, startVertex, endVertex);
    }

    int source;
    printf("Enter the source vertex for DFS: ");
    scanf("%d", &source);

    printf("DFS Traversal starting from vertex %d: ", source);
    DFS(graph, source);

    // Free allocated memory
    for (int i = 0; i < V; i++) {
        struct Node* current = graph->adjList[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjList);
    free(graph);

    return 0;
}