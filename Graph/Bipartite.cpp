// Bipartite Graph :-
// * Divide all vertices of graph in two sets such that edges are from Set-1 to Set-2 only
// * In Case of tree(or No cycles) the graph is always Bipartite 
// * Odd length cycle is always NON - Bipartite Graph

// Applications:-
// * Bipartite graph can be used in the medical field in the detection of lung cancer, throat cancer etc.
// * Used in search advertising and e-commerce for similarity ranking.
// * Predict movie preferences of a person.

// To check Bipartitness of a graph we can color graph according to the adjacent vertices..

class Solution {
    bool dfs(vector<vector<int>>& graph, int node, vector<int>&vis, int parent, int color){
        
        vis[node] = color;
        
        for(int i = 0; i < graph[node].size(); i++){
            int nbr = graph[node][i];
            if(vis[nbr] == 0){
                bool subProb = dfs(graph, nbr, vis, node, 3 - color);
                if(!subProb){
                    return false;
                }
            }
            else if(nbr != parent && color == vis[nbr]){
                return false;
            }
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                bool check = dfs(graph, i, vis, -1, 1);
                if(check == false){
                    return false;
                }
            }
        }
        
        return true;
    }
};