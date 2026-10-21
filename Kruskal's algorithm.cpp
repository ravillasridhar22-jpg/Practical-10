
#include <iostream>
using namespace std;

int main() {
    int n, e;
    int u[20], v[20], w[20];
    int parent[10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < e; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int minCost = 0;
    int count = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (count < n - 1) {
        int min = 999;
        int k = -1;

        for (int i = 0; i < e; i++) {
            if (w[i] < min) {
                min = w[i];
                k = i;
            }
        }

        if (k == -1) {
            cout << "Graph is not connected.\n";
            return 0;
        }

        int a = u[k];
        int b = v[k];

        while (parent[a] != a)
            a = parent[a];

        while (parent[b] != b)
            b = parent[b];

        if (a != b) {
            cout << u[k] << " - " << v[k]
                 << " : " << w[k] << endl;

            minCost += w[k];
            parent[a] = b;
            count++;
        }

        w[k] = 999;
    }

    cout << "Minimum cost of MST: " << minCost << endl;

    return 0;
}
