class Solution {
  bool isSafe(vector<vector<char>>& board,int row,int col,char val){
     for(int i = 0;i<9;i++){
      if(board[i][col]==val){
        return false;
      }
     }

    for(int i = 0;i<9;i++){
      if(board[row][i]==val){
        return false;
      }
     }

     int newrow = (row/3)*3;
     int newcol = (col/3)*3;

     for(int i = 0;i<3;i++){
      for(int j =0;j<3;j++){
        if(board[newrow+i][newcol+j]==val){
          return false;
        }   
      }
      
     }
     return true;

  }

  bool solve(vector<vector<char>>& board,int row , int col){
    if(row==9){
      return true;
    }
    int nextrow = row;
    int nextcol = col+1;
    if(nextcol==9){
      nextcol = 0;
      nextrow = nextrow+1;
    }
    
    if(board[row][col]!='.'){
      return solve(board,nextrow,nextcol);
    }

    for(char i = '1' ; i<='9';i++){
      if(isSafe(board,row,col,i)){
        board[row][col]=i;

        if(solve(board,nextrow,nextcol)){
          return true;
        }
           board[row][col]='.'; 
      }
    }

    return false;

  }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solve(board,0,0);
    }
};