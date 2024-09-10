#include <iostream>
#include <vector>
#include <functional>
using namespace std;

enum Color
{
    WHITE = 0,
    BLACK = 1,
    GRAY = 2
};

bool dfs(vector<vector<int>> &graph, int v, vector<int> &visited){
    visited[v] = 1;

    for (int to: graph[v])
    {
        if (visited[to] == 0 && dfs(graph, to, visited) || visited[to] == 1)
        {
            return true;
        }         
    }
    visited[v] = 2;
    return false;
}

bool find_cycle(const vector<vector<int>> &g)
{
    vector<Color> c(g.size());
    function<bool(int)> dfs = [&](int v, int pv = -1){
        c[v] = GRAY;
        for(int u: g[v]){
            if(c[u] == GRAY || c[u] == WHITE && dfs(u)){
                return true;
            }               
        }
        c[v] = BLACK;
        return false;
    };

    for (int v = 0; v < g.size(); ++v){
        if(c[v] == WHITE && dfs(v)){
            return true;
        }
    }
    return false;
}

// vector<vector<int>> to_adj_list(const vector<pair<int, int>> &pg, int n){
//     vector<vector<int>> g(n);
//     for (auto&[v, u] : pg){
//         g[v].push_back(u);
//     }
//     return g;


int main(int argc, char *argv[])
{
    vector<vector<int>> g = {{1}, 
                             {2}, 
                             {3},
                             {}};
    vector<vector<int>> mg = {{0, 1, 1}, 
                              {0, 3, 3}, 
                              {0, 0, 0}};
    vector<pair<int, int>> pg = {{1, 2}, {5, 6}};


    cout << find_cycle(g) << endl;
    return 0;
}