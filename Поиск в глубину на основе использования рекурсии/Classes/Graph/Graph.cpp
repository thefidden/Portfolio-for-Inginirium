#include "Graph.h"

using namespace std;

Graph::Graph () {

}

Graph &Graph::setAdjacency (vector <vector <int>> adjacency) {
    this->adjacency = adjacency;

    for(int vertexNumber = 0; vertexNumber < this->adjacency[0].size(); ++vertexNumber)
        vertexArr.push_back({
                vertexNumber, /// Номер вершины
                0, /// Уровень вершины
                false, /// Посещенность вершины
                {} /// Маршрут к вершине
        });

    return *this;
}

Graph &Graph::setDistances (vector <vector <int>> distances) {
    this->distances = distances;
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
                minDistances[nextNextPoint] = min(
                        minDistances[nextNextPoint],
                        minDistances[nextPoint] + distances[nextPoint][nextNextPoint]
                );
    }

    return minDistances;
}

void Graph::breadthFirstSearch (int start) {
    queue <Vertex> vertexQueue;

    this->vertexArr[start] = {
            start, /// Номер вершины
            0, /// Уровень вершины
            true, /// Посещенность вершины
            {start + 1} /// Маршрут к вершине
    };
    vertexQueue.push(vertexArr[start]);  /// Помещаем в очередь стартовую вершину

    while(!vertexQueue.empty()) { /// Пока очередь непустая
        for(int i = 0; i < this->adjacency[0].size(); ++i) /// Рассматриваем все вершины
            if(adjacency[vertexQueue.front().number][i] &&
               !vertexArr[i].isVisited) { /// Проверка, что текущая вершина соединена с рассматриваемой вершина и что рассматриваемая вершина не посещена
                vertexArr[i].isVisited = true; /// Отмечаем посещенность рассматриваемой вершины

                vertexArr[i].path = vertexQueue.front().path;
                vertexArr[i].path.push_back(i + 1); /// Помещаем в путь к вершине текущую вершину

                vertexArr[i].level = vertexArr[i].path.size() -
                                     1; /// Присваиваем значению уровня рассматриваемой вершины значение длины маршрута от начальной вершины

                vertexQueue.push(vertexArr[i]); /// Помещаем в очередь рассматриваемую вершину
            }
        vertexQueue.pop(); /// Удаляем из очереди текущую вершину
    }
}

void Graph::depthFirstSearch (int start) {
    stack <Vertex> vertexStack;

    this->vertexArr[start] = {
            start, /// Номер вершины
            0, /// Уровень вершины
            true, /// Посещенность вершины
            {start + 1} /// Маршрут к вершине
    };
    vertexStack.push(vertexArr[start]);  /// Помещаем в стэк стартовую вершину

    while(!vertexStack.empty()) { /// Пока стек непустой
        Vertex currentVertex = vertexStack.top();
        vertexStack.pop();

        for(int i = 0; i < this->adjacency[0].size(); ++i)  /// Рассматриваем все вершины
            if(this->adjacency[currentVertex.number][i] && !vertexArr[i].isVisited) {
                vertexArr[i].isVisited = true; /// Отмечаем посещенность рассматриваемой вершины

                vertexArr[i].path = currentVertex.path;
                vertexArr[i].path.push_back(i + 1); /// Помещаем в путь к вершине текущую вершину

                vertexArr[i].level = this->vertexArr[i].path.size() -
                                     1; /// Присваиваем значению уровня рассматриваемой вершины значение длины маршрута от начальной вершины

                vertexStack.push(vertexArr[i]);
            }
    }
}

void Graph::depthFirstSearchRecursive (int currentVertex, int previousVertex) {
    this->vertexArr[currentVertex].isVisited = true; /// Отмечаем посещенность рассматриваемой вершины

    if(previousVertex != -1) /// Если существует предыдущая вершина
        this->vertexArr[currentVertex].path = this->vertexArr[previousVertex].path; /// Задать маршрут к текущей вершине равным маршруту к предыдущей вершине

    this->vertexArr[currentVertex].path.push_back(currentVertex + 1); /// Добавить к маршруту к текущей вершине номер текущей вершины
    this->vertexArr[currentVertex].level = this->vertexArr[currentVertex].path.size() - 1;

    for(int i = 0; i < this->adjacency[0].size(); ++i) /// Рассматриваем все вершины
        if(this->adjacency[currentVertex][i] && !vertexArr[i].isVisited)
            return this->depthFirstSearchRecursive(i, currentVertex);
}

vector <Vertex> Graph::getVertexes () {
    return this->vertexArr;
}
