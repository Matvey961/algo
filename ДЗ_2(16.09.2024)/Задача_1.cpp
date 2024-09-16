#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

vector<int> top_sort(const vector<vector<int>> &g){
    // Вектор, который хранит степень вершины (число входящих ребер)
    vector<int> degree(g.size(), 0); 
    for (size_t v = 0; v < g.size(); v++)
    {
        for(int x: g[v]){
            degree[x]++;
        }
    }

    queue<int> q;
    for (size_t i = 0; i < g.size(); i++)
    {
        // Если степень вершины 0, то добавляем очередь, т. к. из вершины больше никуда попасть нельзя
        if (degree[i] == 0)
        {
            q.push(i);
        }
        
    }

    vector<int> result;
    while(!q.empty()){
        int w = q.front();
        q.pop();
        result.push_back(w);

        // Понижаем степени всех вершин-соседей
        for (int v: g[w])
        {
            degree[v]--;
            // Также, если степень 0, то добавляем в очередь
            if (degree[v] == 0)
            {
                q.push(v);
            }
            
        }
        
    }
    return result;
    
}

int main(){
    vector<vector<int>> g = {{2}, {3, 4}, {4, 5}, {5}, {}};
    vector<int> res = top_sort(g);
    for(int v: res){
        cout << v << endl;
    }
}