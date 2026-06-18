class Solution {
    // private:
    // int result(vector<int>& nums, int mid){
    //     int count =0;
    //     for(int i : nums){
    //         if(mid<=i){
    //             count++;
    //         }
    //     }
    //     return count;
    // }
public:
    int findKthLargest(vector<int>& nums, int k) {
    //     int s =nums[0];
    //     int e = nums[0];
    //     for(int i : nums){
    //         s = min(s , i);
    //         e = max(e,i);
    //     }

    //     int ans = nums[0];
    //     while(s<=e){
    //         int mid = s + (e-s)/2;
    //         int result1 = result(nums,mid);
    //         if(k<=result1){
    //             ans = mid;
    //             s = mid+1;
    //         }
    //         else{
    //             e = mid -1;
    //         }
    //     }
    //     return ans;
    // }


    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i = 0;i<nums.size();i++){
      if(i<k){
        pq.push(nums[i]);
      }
      else if(nums[i]>pq.top()){
        pq.pop();
        pq.push(nums[i]);
      } 
    }
    return pq.top();
    }
};