// 3min 1 AC
ass Queue {
private:
    stack<int> st;
public:
    // Push element x to the back of queue.
    void push(int x) {
        st.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> st_reverse;
        while(!st.empty()) {
            st_reverse.push(st.top());
            st.pop();
        }
        
        st_reverse.pop();
        
        while(!st_reverse.empty()) {
            st.push(st_reverse.top());
            st_reverse.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        stack<int> st_reverse;
        while(!st.empty()) {
            st_reverse.push(st.top());
            st.pop();
        }
        int result = st_reverse.top();
        while(!st_reverse.empty()) {
            st.push(st_reverse.top());
            st_reverse.pop();
        }
        return result;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st.empty();
    }
};
