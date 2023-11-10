/*
* Пример ввода данных
* 4
* 0 10 15 20
* 10 0 35 25
* 15 35 0 30
* 20 25 30 0
Результат: 80
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int n; // количество городов
vector<vector<int>> graph; // вес ребер графа
vector<int> path; // путь коммивояжера
vector<bool> visited; // посещенные города
int minPath = INF; // минимальная длина пути

void TSP(int u, int len, int count) {
    if (count == n && graph[u][0] != 0) {
        minPath = min(minPath, len + graph[u][0]);
        return;
    }

    for (int v = 0; v < n; v++) {
        if (!visited[v] && graph[u][v] != 0) {
            visited[v] = true;
            path.push_back(v);
            TSP(v, len + graph[u][v], count + 1);
            path.pop_back();
            visited[v] = false;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    cin >> n;
    graph.resize(n, vector<int>(n));
    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    visited[0] = true;
    path.push_back(0);
    TSP(0, 0, 1);

    cout << "Минимальная длина пути коммивояжера: " << minPath << endl;

    return 0;
}
