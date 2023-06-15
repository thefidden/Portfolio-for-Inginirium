#include "Graph.h"

using namespace std;

Graph::Graph () {

}

Graph &Graph::setAdjacency (vector <vector <int>> adjacency) {
    this->adjacency = adjacency;
}

Graph &Graph::setDistances (vector <vector <int>> distances) {
    this->distances = distances;
}

vector <Vertex> Graph::searchInWidth (int start) {
    int vertexAmount = adjacency[0].size();
    vector <Vertex> vertexArr;
    queue <Vertex> vertexQueue;

    for(int vertexNumber = 0; vertexNumber < vertexAmount; ++vertexNumber)
        vertexArr.push_back({
                vertexNumber, /// Номер вершины
                0, /// Уровень вершины
                false /// Посещенность вершины
        });

    vertexArr[start].isVisited = true; /// Отмечаем посещенность стартовой вершины
    vertexQueue.push({ /// Помещаем в очередь стартовую вершину
            start,
            0,
            true
    });

    while(!vertexQueue.empty()) { /// Пока очередь непустая
        for(int i = 0; i < vertexAmount; ++i) /// Рассматриваем все вершины
            if(adjacency[vertexQueue.front().number][i] && !vertexArr[i]
                    .isVisited) { /// Проверка, что текущая вершина соединена с рассматриваемой вершина и что рассматриваемая вершина не посещена
                vertexArr[i].level = vertexQueue.front().level +
                                     1; /// Присваиваем значению уровня рассматриваемой вершины значение текущей вершины, увеличенное на 1
                vertexArr[i].isVisited = true; /// Отмечаем посещенность рассматриваемой вершины
                vertexQueue.push(vertexArr[i]); /// Помещаем в очередь рассматриваемую вершину
            }
        vertexQueue.pop(); /// Удаляем из очереди текущую вершину
    }

    return vertexArr;
}

vector <int> Graph::getMinDistances (int start, int end) {
    int vertexes = this->distances[0].size(), inf = INT_MAX;

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
    }

    return minDistances;
}