#include <iostream>
#include <vector>
#include <functional>
using namespace std;

bool mut_achieved(int a, int b, const vector<vector<int>> &graph)
{
    vector<int> visited1(graph.size());
    vector<int> visited2(graph.size());

    function<void(int, vector<int>&)> dfs = [&] (int v, vector<int> &visited)
    {
        if (visited[v]){
            return;
        } 
        visited[v] = 1;

        for (auto i : graph[v])
        {
            dfs(i, visited);
        }
    };

    dfs(a, visited1);
    dfs(b, visited2);

    return visited1[a] && visited2[b];
}


int main(){
    vector<vector<int>> g = {{1}, {2}, {0}, {}};
    
    cout << mut_achieved(0, 1, g) << endl;
}