class MyStack {
    // Two queues
    queue<int> q1, q2;
    // to maintain the length of the stack
    int len;
public:
    MyStack() {
       len = 0;
    }
    
    void push(int x) {
        len++;
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
    
    int pop() {
        if(q1.empty())
           return -1;
        
        int top = q1.front();
        q1.pop();
        len--;
        return top;
    }
    
    int top() {
        if(q1.empty())
            return -1;
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};