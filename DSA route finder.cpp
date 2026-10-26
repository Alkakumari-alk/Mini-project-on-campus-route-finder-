
#include <stdio.h>
#include <string.h>

#define V 8
#define NAME 30

// Campus locations
char locations[V][NAME] = {
    "Main Gate", "Library", "Block 1", "Block 2",
    "Cafeteria", "Auditorium", "Parking", "Lab"
};

// Adjacency list
int adj[V][V];
int degree[V] = {0};

// Add an undirected path between two locations
void addEdge(int u, int v) {
    adj[u][degree[u]++] = v;
    adj[v][degree[v]++] = u;
}

// Display all campus locations
void displayLocations() {
    int i;
    printf("\nCampus Locations:\n");

    for (i = 0; i < V; i++) {
        printf("%d. %s\n", i, locations[i]);
    }
}

// Convert location number into a valid index
int getLocation() {
    int x;

    printf("Enter location number (0-7): ");

    if (scanf("%d", &x) != 1) {
        printf("Invalid input!\n");
        return -1;
    }

    if (x < 0 || x >= V) {
        printf("Invalid location number!\n");
        return -1;
    }

    return x;
}

// Display graph as an adjacency list
void displayGraph() {
    int i, j;

    printf("\nAdjacency List:\n");

    for (i = 0; i < V; i++) {
        printf("%s -> ", locations[i]);

        for (j = 0; j < degree[i]; j++) {
            printf("%s", locations[adj[i][j]]);

            if (j < degree[i] - 1)
                printf(", ");
        }

        printf("\n");
    }
}

// BFS: Find shortest route in an unweighted graph
void BFS(int source, int destination) {
    int visited[V] = {0};
    int parent[V];
    int queue[V];
    int front = 0, rear = 0;
    int i, current;
    int path[V], count = 0;

    for (i = 0; i < V; i++)
        parent[i] = -1;

    visited[source] = 1;
    queue[rear++] = source;

    while (front < rear) {
        current = queue[front++];

        if (current == destination)
            break;

        for (i = 0; i < degree[current]; i++) {
            int next = adj[current][i];

            if (!visited[next]) {
                visited[next] = 1;
                parent[next] = current;
                queue[rear++] = next;
            }
        }
    }

    if (!visited[destination]) {
        printf("\nNo route exists between these locations.\n");
        return;
    }

    // Reconstruct path using parent array
    current = destination;

    while (current != -1) {
        path[count++] = current;
        current = parent[current];
    }

    printf("\nShortest route using BFS:\n");

    for (i = count - 1; i >= 0; i--) {
        printf("%s", locations[path[i]]);

        if (i > 0)
            printf(" -> ");
    }

    printf("\nNumber of edges: %d\n", count - 1);
}

// DFS: Display all reachable locations
void DFS(int current, int visited[]) {
    int i;

    visited[current] = 1;
    printf("%s\n", locations[current]);

    for (i = 0; i < degree[current]; i++) {
        int next = adj[current][i];

        if (!visited[next])
            DFS(next, visited);
    }
}

// Display reachable and disconnected locations
void showReachable(int source) {
    int visited[V] = {0};
    int i;

    printf("\nLocations reachable from %s:\n",
           locations[source]);

    DFS(source, visited);

    printf("\nDisconnected from %s:\n", locations[source]);

    for (i = 0; i < V; i++) {
        if (!visited[i])
            printf("%s\n", locations[i]);
    }
}

int main() {
    int choice, source, destination;

    // Create the campus graph
    addEdge(0, 1);  // Main Gate - Library
    addEdge(0, 6);  // Main Gate - Parking
    addEdge(1, 2);  // Library - Block 1
    addEdge(1, 4);  // Library - Cafeteria
    addEdge(2, 3);  // Block 1 - Block 2
    addEdge(2, 7);  // Block 1 - Lab
    addEdge(3, 5);  // Block 2 - Auditorium
    addEdge(4, 5);  // Cafeteria - Auditorium

    do {
        printf("\n===== CAMPUS ROUTE FINDER =====\n");
        printf("1. Display Locations\n");
        printf("2. Display Graph\n");
        printf("3. Find Shortest Route (BFS)\n");
        printf("4. Show Reachable Locations (DFS)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            return 0;
        }

        switch (choice) {
            case 1:
                displayLocations();
                break;

            case 2:
                displayGraph();
                break;

            case 3:
                displayLocations();

                source = getLocation();
                if (source == -1)
                    break;

                destination = getLocation();
                if (destination == -1)
                    break;

                BFS(source, destination);
                break;

            case 4:
                displayLocations();

                source = getLocation();
                if (source == -1)
                    break;

                showReachable(source);
                break;

            case 5:
                printf("Exiting Campus Route Finder.\n");
                break;

            default:
                printf("Invalid menu choice!\n");
        }

    } while (choice != 5);

    return 0;
}
