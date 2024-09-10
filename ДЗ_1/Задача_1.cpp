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





int main(){
    vector<vector<int>> list = {{1,5}, {2, 5}, {3}, {5,4}, {0}, {4}, {}};
    vector<pair<int, int>> edges = {{0, 1}, {0, 5}, {1, 5}, {1, 2}, {2, 3}, {3, 5}, {3, 4}, {4, 0}, {5, 2}, {5, 4}};
    vector<vector<int>> mat = {{0, 1, 0, 0, 0, 1, 0},                               
                               {0, 0, 1, 0, 0, 1, 0},
                               {0, 0, 0, 1, 0, 0, 0},
                               {0, 0, 0, 0, 1, 1, 0},
                               {1, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 1, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0}};

    vector<vector<int>> res1 = list_to_mat(list);
    vector<vector<int>> res2 = edge_to_mat(edges, 7);    

    // for (size_t i = 0; i < res2.size(); i++)
    // {
    //     for (size_t j = 0; j < res2.size(); j++)
    //     {
    //         cout << res2[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<int>> res3 = mat_to_list(mat);
    for (size_t i = 0; i < res3.size(); i++)
    {
        for (size_t j = 0; j < res3[i].size(); j++)
        {
            cout << res3[i][j] << " ";
        }
        cout << endl;
    }
    
    
}