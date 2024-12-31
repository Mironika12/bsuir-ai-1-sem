#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(int v, vector<vector<int>>& adj) {
    vector<int> color(v, -1);
    for (int start = 0; start < v; ++start) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                
                for (int neighbor : adj[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "ru");
    int vertices, edges;
    cout << "Введите количество вершин и рёбер: ";
    cin >> vertices >> edges;

    vector<vector<int>> adj(vertices);

    cout << "Введите рёбра (формат: вершина1 вершина2):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;

        if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
            cout << "Ошибка: вершины должны быть в диапазоне от 0 до " << vertices - 1 << "." << endl;
            return 1;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isBipartite(vertices, adj)) {
        cout << "Граф является двудольным." << endl;
    }
    else {
        cout << "Граф не является двудольным." << endl;
    }

    return 0;
}