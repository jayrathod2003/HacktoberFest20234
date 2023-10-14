#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 1e9;

int tspBruteForce(vector<vector<int>>& graph, vector<int>& path, vector<bool>& visited, int current, int n, int cost) {
    if (n == 0) {
        return graph[current][0]; // Return to the starting city
    }

    int minCost = INF;

    for (int next = 0; next < graph.size(); next++) {
        if (!visited[next] && graph[current][next] != 0) {
            visited[next] = true;
            path.push_back(next);

            int newCost = cost + graph[current][next];

            int subproblem = tspBruteForce(graph, path, visited, next, n - 1, newCost);

            minCost = min(minCost, subproblem);

            visited[next] = false;
            path.pop_back();
        }
    }

    return minCost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix for the graph:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> path;
    vector<bool> visited(n, false);

    visited[0] = true;
    path.push_back(0);

    int minCost = tspBruteForce(graph, path, visited, 0, n - 1, 0);

    cout << "Minimum Cost: " << minCost << endl;

    return 0;
}
