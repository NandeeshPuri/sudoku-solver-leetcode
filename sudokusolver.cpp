class Solution {
public:
    
    void solveSudoku(vector<vector<char>>& b) {
        vector<char> digits={'1','2','3','4','5','6','7','8','9'};
       helper(digits,b,0,0);
    }
    bool helper(vector<char>& digits,vector<vector<char>>& b,int i, int j){
        if(i==9)
            return true;
        
        if(j==9)
            return helper(digits,b,i+1,0);
        
          if(b[i][j]!='.')
            return helper(digits,b,i,j+1) ;
        
        for(auto d : digits){
            if(isSafe(b,d,i,j)){
                b[i][j]=d;
                bool subProblem=helper(digits,b,i,j+1);
                if(subProblem)
                    return true;
            }
        }
        b[i][j]='.';
        return false;
            
    }
    
    bool isSafe(vector<vector<char>>& b, char d ,int i, int j){
        for(int c=0; c<9; c++)
            if(b[i][c]==d)
                return false;
        
        for(int r=0; r<9; r++)
            if(b[r][j]==d)
                return false;
       int srow=(i/3)*3, scol=(j/3)*3;
        for(int r=srow; r<srow+3; r++)
            for(int c=scol; c<scol+3; c++){
                if(b[r][c]==d)
                    return false;
            }
         return true;
    }
};