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
        
        if(v % 2 == 0){
            return false;
        }

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