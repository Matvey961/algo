#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int min_edges_number_to_bound(const vector<vector<int>> &g){
    vector<int> component_index(g.size(), -1);
    int current_component = 0;
    

    function<void(int)> dfs = [&](int v){
        component_index[v] = current_component;
        for(int u: g[v]){
            if(component_index[u] == -1){
                dfs(u);
            }
        }        
    };

    for (int v = 0; v < g.size(); ++v)
    {
        if (component_index[v] == -1)
        {
            dfs(v);
            ++current_component;
        }        
    }
    
    return current_component - 1;
}

int main(){
    vector<vector<int>> g = {{1}, {}, {3}, {4}, {2}, {}};
    cout << min_edges_number_to_bound(g) << endl;
}