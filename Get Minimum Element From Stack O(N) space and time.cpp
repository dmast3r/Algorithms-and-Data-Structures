
int _stack :: getMin()  {
    if(s.empty())
        return -1;
    return minEle;
}

int _stack :: pop() {
    if(s.empty())
        return -1;
    int element = s.top();
    s.pop();

    if(element < minEle) {
        int temp = minEle;
        minEle = 2 * minEle - element;
        element = temp;
    }
    return element;
}


void _stack :: push(int x)  {
    if(s.empty()) {
        minEle = x;
        s.push(x);
    }

    else if(x < minEle) {
        s.push(2 * x - minEle);
        minEle = x;
    } else
        s.push(x);
}

