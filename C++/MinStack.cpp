class MinStack {
public:
    void push(int x) {
        s.push(x);
        if(minInt.empty() == true)
            minInt.push(x);
        else if(minInt.top() >= x)
            minInt.push(x);
        return;
    }

    void pop() {
        if(s.empty() == false)
        {
            if(minInt.top() == s.top())
            {
                s.pop();
                minInt.pop();
            }
            else
                s.pop();
        }

        return;

    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minInt.top();
    }

private:
    stack<int> s;
    stack<int> minInt;
};
