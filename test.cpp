#include <iostream>
#include <vector>
#include <functional>
using namespace std;\

enum Color
{
    WHITE = 0,
    BLACK = 1,
    GRAY = 2
};

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

//     for (int v = 0; v < g.size(); ++v){
//         if(c[v] == WHITE && dfs(v)){
//             return true;
//         }
//     }
//     return false;
}

int main(){
    vector<vector<int>> vec = {{1},
                               {2},
                               {3},
                               {4},
                               {0}};

    cout << find_cycle(vec) << endl;


}