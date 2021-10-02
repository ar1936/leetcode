class MyQueue {
public:
    stack<int>input,output;
    MyQueue() {
    }
    void push(int x) {
        if(input.size()>0){
            while(input.size()>0){
                int p=input.top();
                output.push(p);
                input.pop();
            }
        }
        input.push(x);
        if(output.size()>0){
            while(output.size()>0){
                int pp=output.top();
                input.push(pp);
                output.pop();
            }
        }
    }
    int pop() {
        if(input.size()>0){
            int y=input.top();
            input.pop();
            return y;
        }
        return -1;
    }
    
    int peek() {
        if(input.size()>0){
            int z=input.top();
            return z;
        }
        return -1;
    }
    bool empty() {
        if(input.size()==0){
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */