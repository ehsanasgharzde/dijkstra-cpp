#include <iostream>

const int MAX_VERTICES = 50;
const int INF = 1000;

using namespace std;


void initPrimitive(int arr[], int size, int value);
void outResults(int dist[], int num_vertices, int source_vertex);
int minVertex(int dist[], int visited[], int num_vertices);
void relax(int graph[MAX_VERTICES][MAX_VERTICES], int dist[], int visited[], int min_vertex, int num_vertices);
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices, int source_vertex);
void getGraph(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices);


int main() {
    int num_vertices;
    cin >> num_vertices;

    int graph[MAX_VERTICES][MAX_VERTICES];
    getGraph(graph, num_vertices);

    int source_vertex;
    cin >> source_vertex;

    dijkstra(graph, num_vertices, source_vertex);

    return 0;
}

void initPrimitive(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}

void outResults(int dist[], int num_vertices, int source_vertex) {
    for (int i = 0; i < num_vertices; i++) {
        cout << i << " ";
        if (dist[i] == INF) {
            cout << INF;
        } else {
            cout << dist[i];
        }
        cout << endl;
    }
}


int minVertex(int dist[], int visited[], int num_vertices) {
    int min_dist = INF;
    int min_vertex = -1;

    for (int v = 0; v < num_vertices; v++) {
        if (visited[v] == 0 && dist[v] < min_dist) {
            min_dist = dist[v];
            min_vertex = v;
        }
    }

    return min_vertex;
}

void relax(int graph[MAX_VERTICES][MAX_VERTICES], int dist[], int visited[], int min_vertex, int num_vertices) {
    for (int u = 0; u < num_vertices; u++) {
        if (visited[u] == 0 && graph[min_vertex][u] != 0 &&
            dist[min_vertex] + graph[min_vertex][u] < dist[u]) {
            dist[u] = dist[min_vertex] + graph[min_vertex][u];
        }
    }
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices, int source_vertex) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];

    initPrimitive(dist, num_vertices, INF);
    initPrimitive(visited, num_vertices, 0);

    dist[source_vertex] = 0;

    while (true) {
        int min_vertex = minVertex(dist, visited, num_vertices);

        if (min_vertex == -1)
            break;

        visited[min_vertex] = 1;
        relax(graph, dist, visited, min_vertex, num_vertices);
    }

    outResults(dist, num_vertices, source_vertex);
}

void getGraph(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            cin >> graph[i][j];
        }
    }
}