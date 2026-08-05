class Mat{
  
  public:
  int val;
  int r;
  int c;
  Mat(int v,int row,int col){
    val = v;
    r = row;
    c = col;
  }

  bool operator>(const Mat& other) const {
    return val > other.val;
}
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      priority_queue<Mat,vector<Mat>,greater<Mat>>pq;
      for(int i = 0;i<matrix.size();i++){
        pq.push({matrix[i][0],i,0});
      }
      int rowSize = matrix.size();
      int colSize = matrix[0].size();
      int count = 0;
      while(!pq.empty()){
        auto cl = pq.top();
        pq.pop();
        count++;
        if(count==k){
          return cl.val;
        }
        if(cl.c + 1 <colSize){
          pq.push({matrix[cl.r][cl.c+1],cl.r,cl.c+1});
        }

      }
      return -1;
        
    }
};