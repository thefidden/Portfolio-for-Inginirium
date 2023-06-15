#include "libraries.h"

using namespace std;

int main () {
    SetConsoleOutputCP(65001);

    Graph graph;

    graph.setAdjacency({
            {0, 1, 0, 1, 0, 0, 0, 0, 0},
            {1, 0, 1, 0, 1, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 1, 0, 0, 0},
            {1, 0, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 1},
            {0, 0, 0, 1, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1, 0, 1, 0, 1},
            {0, 0, 0, 0, 0, 1, 0, 1, 0}
    });  /// Матрица смежности

    vector <Vertex> arr = graph.searchInWidth(stoi(input("Введите начальную точку: ")) - 1);

    stable_sort(arr.begin(), arr.end(), [] (Vertex a, Vertex b) {
        return a.level < b.level;
    }); /// Сортировка массива вершин по параметру уровня

    for(auto vertex: arr)
        cout << vertex.number + 1 << ": " << vertex.level << endl;

    system("pause");
    return 0;
}