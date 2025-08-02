class MinStack {
public:
    stack<int> st;
    stack<int> min;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(min.empty() || min.top() >= val)
            min.push(val);
    }
    
    void pop() {
        if(st.top() == min.top()){
            min.pop();
        }

        st.pop();
    }
    
    int top() {
        if(st.empty())
            return -1;
        
        return st.top();
    }
    
    int getMin() {
        if(min.empty())
            return -1;

        return min. top();        
    }
};
