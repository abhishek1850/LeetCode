class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      if(k==1){
        return nums;
      }
      int n = nums.size();

      vector<int>ans;
      // for(int i = 0;i<=nums.size()-k;i++){
      //   int maxi = INT_MIN;
      //   for(int j = i;j<k+i;j++){
      //     maxi = max(maxi,nums[j]);

      //   }
      //   ans.push_back(maxi);
      // }

      // return ans;

      deque<int>q;
      for(int i = 0; i<n;i++){
        if(!q.empty() && q.front()<=i-k){
          q.pop_front();
        }
        while(!q.empty() && nums[i]>=nums[q.back()]){
          q.pop_back();
        }

        q.push_back(i);
        if(i>=k-1){
          ans.push_back(nums[q.front()]);
        }
      }
      return ans;
        
    }
};