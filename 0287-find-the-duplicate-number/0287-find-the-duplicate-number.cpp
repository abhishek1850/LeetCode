class Solution {
public:
    int findDuplicate(vector<int>& arr) {
    //    for(int i=0;i<arr.size();i++){
    //     if(arr[abs(arr[i])-1]<0){
    //         return abs(arr[i]);
    //     }
    //     else{
    //         arr[abs(arr[i])-1]*=(-1);
    //     }
    //    }
    //    return 0;

    // int fast = arr[0],slow=arr[0];
    // do{
    //     slow = arr[slow];
    //     fast = arr[arr[fast]];  
    //  } while(slow!=fast);

    // slow = arr[0];
    // while(slow!=fast){
    //     slow = arr[slow];
    //     fast = arr[fast];  
    // }
    // return slow;
    // }


    for(int i =0;i<arr.size();i++){
      int val = abs(arr[i]);
      if(arr[val]<0){
        return val;
      }
      else{
        arr[val]=-arr[val];
      }
      
 
       }
       return -1;
          }
};