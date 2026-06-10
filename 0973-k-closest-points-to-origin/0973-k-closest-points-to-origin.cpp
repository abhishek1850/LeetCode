class Points{
  public:
  int idx;
  int dist;
  vector<int>s;

  Points(int i , int d, vector<int> ss){
    idx = i;
    dist = d;
    s = ss;
  }


  bool operator < (const Points& obj) const {
    return this->dist > obj.dist;
  }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

      vector<Points>store;
      
      for(int i = 0;i<points.size();i++){
        int dist = (points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
        store.push_back(Points(i,dist,points[i]));
      }

      priority_queue<Points>pq(store.begin(),store.end());
      vector<vector<int>>ans;
      for(int i = 0;i<k;i++){
        ans.push_back(pq.top().s);
        pq.pop();
      }
        
        return ans;
    }
};