class MyQueue {
public:
    stack<int>newest, oldest;
    MyQueue() {   
    }

    void push(int x) {
        newest.push(x);
    }
    
    void shiftstack(){
        if(oldest.empty())
            while(!newest.empty()){
                int val = newest.top();
                oldest.push(val);
                newest.pop();
            }
    }
    
    int pop() {
        shiftstack();
        int val = oldest.top();
        oldest.pop();
        return val;
    }
    
    int peek() {
        shiftstack();
        return oldest.top();
    }
    
    bool empty() {
        return newest.empty() && oldest.empty();
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



// class Queue {
//     stack<int> input, output;
// public:

//     void push(int x) {
//         input.push(x);
//     }

//     void pop(void) {
//         peek();
//         output.pop();
//     }

//     int peek(void) {
//         if (output.empty())
//             while (input.size())
//                 output.push(input.top()), input.pop();
//         return output.top();
//     }

//     bool empty(void) {
//         return input.empty() && output.empty();
//     }
// };