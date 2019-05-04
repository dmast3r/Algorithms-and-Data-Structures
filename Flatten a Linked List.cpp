/* 
Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.

You have to flatten the linked list to a single linked list which is sorted.

       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45

and after flattening it, the sorted linked list looks like:

 5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.

The  node structure has 3 fields as mentioned. A next pointer, a bottom pointer and a data part.

Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
}; 

Solution - The question is similar to and a slight modification over merging of two sorted Linked Lists.
*/

// merge two sorted Linked Lists
Node *mergeLinkedLists(Node *head_a, Node *head_b) {
    // the below two if checks are similar to merging of Linked List
    // if you reach the end of the Linked List then
    // return pointer to the current node of the other
    if(head_a == nullptr)
        return head_b;
        
    if(head_b == nullptr)
        return head_a;
    
    // recursively build a sub linked list from here    
    Node *res = nullptr;
    
    // the below two if checks are the same in merging two sorted
    // linked list, expect that we are moving downwards in each list
    if(head_a -> data <= head_b -> data) {
        res = head_a;
        res -> bottom = mergeLinkedLists(head_a -> bottom, head_b);
    }
    
    else {
        res = head_b;
        res -> bottom = mergeLinkedLists(head_a, head_b -> bottom);
    }
    
    return res;
}

// Function which returns the  root of the flattened linked list. 
Node *flatten(Node *root) {
    // if the list is empty or has a single 'horizontal' node
    // then simply return the list
    if(root == nullptr or root -> next == nullptr)
        return root;
    
    // recursively first flatten rest of the list then merge it with 
    // the list moving downward from the root
    return mergeLinkedLists(root, flatten(root -> next));    
}
