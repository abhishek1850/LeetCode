// class Points{
//   public:
  
//   int dist;
//   vector<int>s;

//   Points(int d, vector<int> ss){
//     dist = d;
//     s = ss;
//   }
//   bool operator < (const Points& obj) const {
//     return this->dist > obj.dist;
//   }
// };
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

      // vector<Points>store;


      priority_queue<
      pair<int,vector<int>>,
      vector<pair<int,vector<int>>>,
      greater<pair<int,vector<int>>>
      >pq;
      
      // for(int i = 0;i<points.size();i++){
      //   int dist = (points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
      //   store.push_back(Points(dist,points[i]));
      // }

      for(auto & p : points){
        int dist = p[0]*p[0]+p[1]*p[1];
        pq.push({dist,p});        
      }


      // priority_queue<Points>pq(store.begin(),store.end());
      vector<vector<int>>ans;
      // for(int i = 0;i<k;i++){
      //   ans.push_back(pq.top().s);
      //   pq.pop();
      // }

      for(int i = 0;i<k;i++){
        ans.push_back(pq.top().second);
        pq.pop();
      }
        
        return ans;
    }
};