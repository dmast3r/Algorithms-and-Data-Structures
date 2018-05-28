/*
	Solution : Grow both the stacks in oppposite direction and starting from opposite extremes(0 and size-1)
*/

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the class is
class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
   twoStacks(int n=100){size = n; arr = new int[n]; top1 = -1; top2 = size;}
 
   void push1(int x);
   void push2(int x);
   int pop1();
   int pop2();
};
*/

void twoStacks :: push1(int x) {
    if(top2 - top1 < 2)
        return;
    
    ++top1;
    int pos = top1;
    arr[pos] = x;
}
   
void twoStacks ::push2(int x){
    if(top2 - top1 < 2)
        return;
    
    --top2;
    int pos = top2;
    arr[pos] = x;
}
   

int twoStacks ::pop1() {
    if(top1 < 0)
        return -1;
    
    int pos = top1;
    int elem = arr[pos];
    --top1;
    return elem;
}

int twoStacks :: pop2() {
    if(top2 >= size)
        return -1;
    
    int pos = top2;
    int elem = arr[pos];
    ++top2;
    return elem;
}
