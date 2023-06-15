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
            })  /// Матрица смежности
            .depthFirstSearchRecursive(stoi(input("Введите начальную точку: ")) - 1); /// Рекурсивный поиск в глубину
    vector <Vertex> arr = graph.getVertexes();

    stable_sort(arr.begin(), arr.end(), [] (const Vertex &a, const Vertex &b) {
        return a.path.size() < b.path.size();
    }); /// Сортировка массива вершин по параметру длины маршрута

    for(auto &vertex: arr)
        cout << "Номер: " << vertex.number + 1 << " | "
             << "Маршрут: " << join(vertex.path, " ") << endl;

    system("pause");
    return 0;
}