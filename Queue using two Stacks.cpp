void StackQueue :: push(int x) {
    s1.push(x);
}

int StackQueue :: pop() {
    
    if(s1.empty() and s2.empty())
        return -1;
    
    if(!s2.empty()) {
        int element = s2.top();
        s2.pop();
        return element;
    }
    
    while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    
    int element = s2.top();
    s2.pop();
    return element;
}
