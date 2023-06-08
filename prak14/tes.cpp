#include <iostream>
#include <limits>
#define N 6
#define INF 1000

void Warshall(int graph[N][N], int dist[N][N], int path[N][N]) {
    // Initialize the distance and path matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = graph[i][j];
            if (i == j || graph[i][j] == INF)
                path[i][j] = -1;
            else
                path[i][j] = i;
        }
    }

    // Perform the Warshall's algorithm
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
}

void FindRoute(int start, int end, int path[N][N]) {
    if (path[start][end] == -1) {
        std::cout << "No route exists from " << start << " to " << end << std::endl;
        return;
    }

    std::cout << "Shortest route from " << start << " to " << end << ": ";
    std::cout << start;
    while (start != end) {
        start = path[start][end];
        std::cout << " -> " << start;
    }
    std::cout << std::endl;
}

int main() {
    int graph[N][N] = {{INF, 4, 2, INF, INF, INF},
                       {4, INF, 1, 5, INF, INF},
                       {2, 1, INF, 8, 10, INF},
                       {INF, 5, 8, INF, 2, 6},
                       {INF, INF, 10, 2, INF, 3},
                       {INF, INF, INF, 6, 3, INF}};

    int dist[N][N];
    int path[N][N];

    Warshall(graph, dist, path);

    int start = 1;
    int end = 5;
    FindRoute(start, end, path);

    return 0;
}
