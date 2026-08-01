class Solution {
public:
    bool isPalindrome(int x) {

      long long  reverse = 0;

      long long dummy = x;
      while(x>0){
        reverse = reverse*10+ x%10;
        x = x/10;
      }

      return dummy==reverse;
        
    }
};