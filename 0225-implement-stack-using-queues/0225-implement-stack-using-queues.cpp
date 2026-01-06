class MyStack {
public:
    queue<int> q;

    MyStack() {
    }
    
    void push(int x) {
        q.push(x);               // step 1
        int size = q.size();
        
        // step 2: rotate
        for(int i = 1; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
