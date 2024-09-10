#include <iostream>
#include <vector>
using namespace std;

//Функция преобразования списка смежности в матрицу смежности
vector<vector<int>> list_to_mat(const vector<vector<int>> &data){
    vector<vector<int>> result(data.size(), vector<int>(data.size()));
    for (int v = 0; v < data.size(); v++)
    {
        for(int x: data[v]){
            result[v][x] = 1;
        }
    }   

    return result;
}

//Функция преобразования списка смежности в список ребер
vector<pair<int,int>> list_to_edges(vector<vector<int>> &data){
    vector<pair<int, int>> result;
    for (int v = 0; v < data.size(); v++)
    {
        for(int x: data[v]){
            result.push_back({v, x});
        }
    }   

    return result;
}

//Функция преобразования списка ребер в матрицу смежности
//Замечание: на вход функции подается два аргумента: список ребер и количество вершин графа 
//(т.к. могут присутствовать изолированные вершины)
vector<vector<int>> edge_to_mat(vector<pair<int, int>> &data, int n){
    vector<vector<int>> result(n, vector<int>(n));
    for (auto&[v, u] : data){
        result[v][u] = 1;
    }

    return result;
}

//Функция преобразования списка ребер в список смежности
//Замечание: на вход функции подается два аргумента: список ребер и количество вершин графа 
//(т.к. могут присутствовать изолированные вершины)
vector<vector<int>> edge_to_list(vector<pair<int, int>> &data, int n){
    vector<vector<int>> result(n);
    for (auto&[v, u] : data){
        result[v].push_back(u);
    }

    return result;
}

//Функция преобразования матрицы смежности в список смежности
vector<vector<int>> mat_to_list(vector<vector<int>> &data){
    vector<vector<int>> result(data.size());
    for (int i = 0; i < data.size(); i++)
    {
        for(int j = 0; j < data.size(); j++){
            if (data[i][j] == 1)
            {
                result[i].push_back(j);
            }            
        }
    }
    return result;   
}

//Функция преобразования матрицы смежности в список ребер
vector<pair<int, int>> mat_to_edges(vector<vector<int>> &data){
    vector<pair<int, int>> result;
    for (int i = 0; i < data.size(); i++)
    {
        for(int j = 0; j < data.size(); j++){
            if (data[i][j] == 1)
            {
                result.push_back({i, j});
            }            
        }
    }
    return result; 
}

