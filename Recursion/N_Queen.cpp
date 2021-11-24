// Problem Link -> https://leetcode.com/problems/n-queens/

// Approach - 1 : 
// * We use simple backtracking and To check if the queen is safe or not will check for upper daigonals and upper row

class Solution {
public:
    
    bool isSafe(vector<string> &nQueen, int row, int col, int n){
        
        for(int i = 0; i < row; i++){
            if(nQueen[i][col] == 'Q'){
                return false;
            }
        }
        
        int i = row, j = col;
        
        while(i >= 0 && j >= 0){
            if(nQueen[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }
        
        i = row;
        j = col;
        
        while(i >= 0 && j < n){
            if(nQueen[i][j] == 'Q'){
                return false;
            }
            i--;
            j++;
        }
        
        return true;
    }
    
    void solve(vector<vector<string>> &board, vector<string> &nQueen, int row, int n){
        if(row == n){
            board.push_back(nQueen);
            return;
        }
        
        for(int col = 0; col < n; col++){
            if(isSafe(nQueen, row, col, n)){
                nQueen[row][col] = 'Q';
                solve(board, nQueen, row + 1, n);
                nQueen[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> nQueen (n, string(n, '.'));
        solve(ans, nQueen, 0, n);
        return ans;
    }
};

// Approach - 2 :
// * Here we will do same thing but we optimise the isSafe function from O(3n) to O(1) using hashing
// * We will Branch and Bound Algo in which we make specific patters for both the upper daigonals and upper row

class Solution {
    void solve(vector<vector<string>> &ans, vector<string>&curr, int n, int row, vector<int> &Col, vector<int> &left_daiognal, vector<int> &right_daiognal){
        if(row == n){
            ans.push_back(curr);
            return;
        }
        
        for(int col = 0; col < n; col++){
            if((Col[col] == 0) && (left_daiognal[n - 1 + col - row] == 0) && (right_daiognal[row + col] == 0)){
                Col[col] = 1;
                left_daiognal[n - 1 + col - row] = 1;
                right_daiognal[row + col] = 1;
                
                curr[row][col] = 'Q';
                solve(ans, curr, n, row + 1, Col, left_daiognal, right_daiognal);
                curr[row][col] = '.';
                
                Col[col] = 0;
                left_daiognal[n - 1 + col - row] = 0;
                right_daiognal[row + col] = 0;
            }
        }
    }   
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> Col(n, 0), left_daiognal(2 * n - 1, 0), right_daiognal(2 * n - 1, 0);  
        vector<string> curr(n);
        string s(n, '.');
        
        for(int i = 0; i < n; i++){
            curr[i] = s;
        }
        
        solve(ans, curr,  n, 0, Col, left_daiognal, right_daiognal);
        return ans;
    }
};
