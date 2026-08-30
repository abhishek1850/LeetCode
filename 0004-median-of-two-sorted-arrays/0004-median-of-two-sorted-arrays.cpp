class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>store(nums1.begin(),nums1.end());
        store.insert(store.end(),nums2.begin(),nums2.end());
        sort(store.begin(),store.end());
        if(store.size()%2==1){
          return (double)store[store.size()/2];
        }
        return ((store[store.size()/2]+store[(store.size()/2) -1])/2.0);
    }
};