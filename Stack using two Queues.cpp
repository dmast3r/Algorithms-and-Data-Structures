
// The method push to push element into the stack
void QueueStack :: push(int x)  {
    q1.push(x);
}

// The method pop which return the element popped out of the stack
int QueueStack :: pop() {
    if(q1.empty())
        return -1;

    while(q1.size() > 1) {
        q2.push(q1.front());
        q1.pop();
    }
    int element = q1.front();
    q1.pop();
    while(!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }
    return element;
}
