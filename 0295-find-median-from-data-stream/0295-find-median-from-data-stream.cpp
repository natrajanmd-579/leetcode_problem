class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;


    MedianFinder() {
    }
    
    void addNum(int num) {
        left.push(num);

        if(!left.empty() && !right.empty() && left.top()>right.top()){
            int x=left.top();
            left.pop();
            right.push(x);
        }

        if(left.size() > right.size()+1){
            int x=left.top();
            left.pop();
            right.push(x);
        }
        else if(right.size() > left.size()){
            int x=right.top();
            right.pop();
            left.push(x);
        }
    }
    
    double findMedian() {
        if(left.size() > right.size()){
            return left.top();
        }

        return (left.top()+right.top())/2.0;
    }
};
