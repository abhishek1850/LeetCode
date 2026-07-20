class MedianFinder {
    priority_queue<int>maxpq;
    priority_queue<int,vector<int>,greater<int>>minpq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
      
      if(maxpq.empty() ||  maxpq.top()>=num){
        maxpq.push(num);
      }
      else{
        minpq.push(num);
      }

      if(minpq.size()>maxpq.size()+1){
        maxpq.push(minpq.top());
        minpq.pop();
      }

      if(maxpq.size()>minpq.size()+1){
        minpq.push(maxpq.top());
        maxpq.pop();
      }
    }

    double findMedian() {
      if(minpq.size() == maxpq.size()){
        return (minpq.top()+maxpq.top())/2.0;
      }

      if(minpq.size()>maxpq.size()){
        return minpq.top();
      }
      return maxpq.top();
    }
          
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */