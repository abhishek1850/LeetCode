class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
      // int time = 0;
      // while(tickets[k]!=0){
      //   for(int i = 0;i<tickets.size();i++){
      //     if(tickets[k]==0){
      //       break;
      //     }
      //     if(tickets[i]>0){
      //     time++;
      //     tickets[i]--;
      //   }
      //   }
      // }
      //   return time;


      int time = 0;
      int n = tickets.size();
      for(int i = 0 ;i<n;i++){
        if(i<k){
          if(tickets[i]<=tickets[k]){
            time+=tickets[i];
          }
          else{
            time+=tickets[k];
          }
        }

        else if(i==k){
          time+=tickets[k];
        }
        else{

          if(tickets[i]<tickets[k]){
            time+=tickets[i];
          }
          else{
            time+=tickets[k]-1;
          }
        }
      }
      return time;
    }
};