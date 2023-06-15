#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

const int inf = INT_MAX;

string join (vector <int> arr, string sep) {
    string result;

    for(auto &item: arr)
        result += to_string(item) + sep;

    return result;
}

string input (string request) {
    string result;
    cout << request;
    getline(cin, result);
    return result;
}

int main () {
    SetConsoleOutputCP(65001);

    vector <vector <int >> distances = {
            {inf, 4,   9,   8,   inf, inf},
            {inf, 0,   2,   inf, inf, inf},
            {inf, inf, 0,   inf, inf, 3},
            {8,   2,   4,   0,   6,   inf},
            {inf, 2,   inf, inf, 0,   3},
            {inf, inf, inf, 9,   inf, inf}
    };

    int start = stoi(input("Введите пункт отправления: ")) - 1, vertexes = distances[0].size();

    vector <bool> visited;
    vector <int> minDistances;

    visited.resize(vertexes);
    minDistances.resize(vertexes);

    for(int i = 0; i < vertexes; ++i) {
        minDistances[i] = distances[start][i];
        visited[i] = false;
    }

    minDistances[start] = 0;
    visited[start] = true;

    for(int i = 0; i < minDistances.size(); ++i)
        cout << i << ":" << minDistances[i] << ' ';
    cout << endl;

    for(int currentPoint = 0, nextPoint = 0; currentPoint < vertexes; ++currentPoint) {
        int minRoute = inf;

        for(int point = 0; point < vertexes; ++point)
            if(!visited[point] && minDistances[point] < minRoute) {
                minRoute = minDistances[point];
                nextPoint = point;
            }

        visited[nextPoint] = true;

        for(int nextNextPoint = 0; nextNextPoint < vertexes; ++nextNextPoint)
            if(!visited[nextNextPoint] && distances[nextPoint][nextNextPoint] != inf)
                minDistances[nextNextPoint] = min(minDistances[nextNextPoint],
                        minDistances[nextPoint] + distances[nextPoint][nextNextPoint]);

        for(int i = 0; i < minDistances.size(); ++i)
            cout << i << ":" << minDistances[i] << ' ';
        cout << endl;
    }

    for(int i = 0; i < vertexes; ++i)
        cout << start + 1 << " -> " << i + 1 << " = " << minDistances[i] << endl;

    cout << join(minDistances, " ");

    system("pause");
    return 0;
}
