## Dijkstra's Algorithm in C++

This C++ program demonstrates Dijkstra's algorithm for finding the shortest path from a source vertex to all other vertices in a weighted graph represented as an adjacency matrix.

### How to Use

1. Compile the program using your preferred C++ compiler.

2. Run the compiled program.

3. Follow the on-screen instructions to provide the necessary input:
   - Input the number of vertices in the graph.
   - Input the adjacency matrix representing the weighted graph.
   - Input the source vertex from which you want to find the shortest paths.

4. The program will compute and display the shortest distances from the source vertex to all other vertices.

### Input Example

Suppose you want to find the shortest paths in the following weighted graph with 4 vertices:

Number of vertices: 4
Adjacency Matrix (4x4):
0 2 4 0
2 0 1 5
4 1 0 3
0 5 3 0
Source Vertex: 0


### Output Example

The program will output the shortest distances from the source vertex to all other vertices:

Shortest Distances from Source Vertex 0:

Vertex 0: 0
Vertex 1: 2
Vertex 2: 3
Vertex 3: 6
