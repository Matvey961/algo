#include <iostream>
#include <vector>
#include <functional>
#include <string>
using namespace std;

vector<vector<int>> edge_to_list(vector<pair<int, int>> &data, int n){
    vector<vector<int>> result(n);
    for (auto&[v, u] : data){
        result[v].push_back(u);
    }

    return result;
}

vector<int> topological_sort(const vector<vector<int>> &g){
    vector<bool> visit(g.size());
    vector<int> order;

    function<void(int)> dfs = [&](int v){
        visit[v] = true;
        for(int u: g[v]){
            if(!visit[u]){
                dfs(u);
            }
        }
        order.push_back(v);
    };

    for (int v = 0; v < g.size(); ++v)
    {
        if (!visit[v])
        {
            dfs(v);
        }
        
    }
    
    reverse(order.begin(), order.end());
    return order;
}

vector<int> cloths_sort(vector<pair<int, int>> edges){
    vector<vector<int>> g = edge_to_list(edges, edges.size());
    vector<int> result = topological_sort(g);    
    return result;    
}


int main(){
    vector<string> cloths_name = {"Пиджак", "Часы", "Брюки", "Рубашка", "Трусы", "Носки", "Туфли", "Галстук", "Ремень"};
    vector<int> cloths = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<pair<int, int>> edges = {{7, 0}, {5, 6}, {3, 8}, {3, 7}, {8, 0}, {4, 2}, {4, 6}, {2, 6}, {2, 8}};
    
    vector<int> res = cloths_sort(edges);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << cloths_name[res[i]] << endl;
    }
    
}