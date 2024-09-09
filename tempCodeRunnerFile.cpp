or (int v = 0; v < g.size(); ++v){
        if(c[v] == WHITE && dfs(v)){
            return true;
        }
    }
    return false;