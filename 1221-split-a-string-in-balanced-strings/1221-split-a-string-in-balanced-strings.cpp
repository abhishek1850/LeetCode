class Solution {
public:
    int balancedStringSplit(string s) {
      int arr[26]={0};
      int count = 0;
      
      for(char ch:s){
         arr[ch-'A']++;
         if(arr['L'-'A']==arr['R'-'A']){
          count++;
          arr['L'-'A']=0;
          arr['R'-'A']=0;
         }

      }
      return count;
        
    }
};