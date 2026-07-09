class MedianFinder {
public:
    priority_queue<int> lmaxh;
    priority_queue<int,vector<int>,greater<int>> rminh;
    MedianFinder() {
        
    }
    void addNum(int num) {
         if(lmaxh.empty() || num<=lmaxh.top()){
            lmaxh.push(num);
         }
         else{
         rminh.push(num);
         }
         if(lmaxh.size() > rminh.size()+1){
            rminh.push(lmaxh.top());
            lmaxh.pop();
         }
         else if(rminh.size()>lmaxh.size()){
            lmaxh.push(rminh.top());
            rminh.pop();
         }
    }
    
    double findMedian() {
          if(lmaxh.size()==rminh.size()){
             double mean= (lmaxh.top()+rminh.top())/2.0;
             return mean;
          }
           return lmaxh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */