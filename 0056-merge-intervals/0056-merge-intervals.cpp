class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(),intervals.end());
        
        vector<vector<int>>store;
        for(int i = 0;i<intervals.size();i++){
          bool val = true;
          vector<int>dummy;
          for(int j = i+1;j<intervals.size();j++){
            if(!dummy.empty()){
              if(dummy[1]>=intervals[j][0]){
                int val = dummy[0];
                int val2 = dummy[1];
                dummy.clear();
                dummy.push_back(val);
                dummy.push_back(max(val2,intervals[j][1]));
                i++;
              }

            }
            else if(intervals[i][1]>=intervals[j][0]){
              dummy.push_back(intervals[i][0]);
              dummy.push_back(max(intervals[i][1],intervals[j][1]));
              i++;
              val = false;
               
            }
          }
          if(val){
            store.push_back(intervals[i]);
          }
          else{
            store.push_back(dummy);
          }
        }
        return store;
    }
};